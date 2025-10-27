#include "../include/SalesFacade.h"
#include "../include/Inventory.h"
#include "../include/PaymentProcessor.h"
#include "../include/OrderBuilder.h"
#include "../include/Order.h"
#include "../include/StockItem.h"
#include "../include/Customer.h" // Needed for method signatures
#include "../include/GreenhouseBed.h"
#include "../include/PlantPrototypeRegistry.h"
#include <algorithm>
#include <iostream>

/**
 * @brief Constructor that "wires" the facade to its subsystems.
 */
SalesFacade::SalesFacade(Inventory* inv,
                         PaymentProcessor* pp,
                         OrderBuilder* ob,
                         GreenhouseBed* greenhouse,
                         PlantPrototypeRegistry* registry)
    : inventory(inv),
      paymentProcessor(pp),
      orderBuilder(ob),
      greenhouseRoot(greenhouse),
      plantRegistry(registry) {
    syncInventoryContext();
}

void SalesFacade::registerCustomer(Customer* customer) {
    if (!customer) {
        return;
    }
    if (std::find(customers.begin(), customers.end(), customer) == customers.end()) {
        customers.push_back(customer);
    }
}

void SalesFacade::unregisterCustomer(Customer* customer) {
    if (!customer) {
        return;
    }
    customers.erase(std::remove(customers.begin(), customers.end(), customer), customers.end());
}

void SalesFacade::setGreenhouseRoot(GreenhouseBed* root) {
    greenhouseRoot = root;
    syncInventoryContext();
}

void SalesFacade::setPlantRegistry(PlantPrototypeRegistry* registry) {
    plantRegistry = registry;
    syncInventoryContext();
}

void SalesFacade::registerPlantType(const std::string& name) {
    if (!inventory || name.empty()) {
        return;
    }
    registeredManualPlants.insert(name);
    inventory->registerPlantType(name);
}

/**
 * @brief Simplifies checking stock.
 * Just a pass-through to the Inventory subsystem.
 */
int SalesFacade::checkStock(std::string plantType) {
    return inventory->getStockCount(plantType);
}

/**
 * @brief Simplifies adding a new item type to the inventory.
 */
void SalesFacade::addItemToInventory(std::string name, double price, bool isPlant) {
    if (!inventory) {
        std::cerr << "[SalesFacade] Inventory subsystem unavailable.\n";
        return;
    }

    if (isPlant) {
        registerPlantType(name);
        PlantInstance* plant = inventory->createPlantInstance(name);
        inventory->additem(new StockItem(name, price, plant));
    } else {
        inventory->additem(new StockItem(name, price, nullptr));
    }
    std::cout << "[SalesFacade] Added " << name << " to inventory." << std::endl;
}

/**
 * @brief Simplifies buying a single item.
 * This is the "happy path" (browse->add->pay).
 */
bool SalesFacade::purchaseItem(Customer* customer, StockItem* item) {
    if (item == nullptr) {
        return false;
    }

    // 1. Check stock (This also handles "insufficient stock" test)
    std::string itemName = item->getname();
    StockItem* itemInStock = inventory->findItem(itemName);

    if (itemInStock == nullptr) {
        std::cout << "[SalesFacade] Purchase failed: " << itemName << " is out of stock." << std::endl;
        return false; // Insufficient stock
    }

    if (customer != nullptr) {
        customer->removeFromCart(itemInStock);
    }

    // 2. Process Payment
    // Using const getter now
    double price = itemInStock->getPrice();
    // In a real app, we'd get customer details from the Customer object
    bool paid = paymentProcessor->processPayment("MockCustomerDetails", price);

    // 3. Update Inventory
    if (paid) {
        // This removes ONE item of this name, per Inventory.h logic
        inventory->removeItem(itemName);
        notifyItemSold(itemName);
        std::cout << "[SalesFacade] Purchase of " << itemName << " complete." << std::endl;
        return true;
    }

    std::cout << "[SalesFacade] Purchase failed: Payment declined." << std::endl;
    return false;
}

/**
 * @brief Simplifies building a complex order.
 */
Order* SalesFacade::buildAndFinalizeOrder(Customer* customer, std::vector<StockItem> items) {
    // 1. Build the order
    orderBuilder->createNewOrder();
    for (StockItem& item : items) {
        // We pass the address of the item in our local vector copy
        orderBuilder->addItem(&item);
    }

    Order* order = orderBuilder->getOrder();
    if (order == nullptr) {
        return nullptr; // Builder failed
    }

    // 2. Process Payment
    double total = order->calculateTotal();
     // Using a mock string since 'customer' is unused
    bool paid = paymentProcessor->processPayment("MockCustomerDetails", total);

    // 3. Finalize and update inventory
    if (paid) {
        order->setOrderStatus("Paid");
        // Remove all items from inventory
        for (StockItem& item : items) {
            // Using const getter now
            if (customer != nullptr) {
                customer->removeFromCart(item.getname());
            }
            const std::string itemName = item.getname();
            inventory->removeItem(item.getname());
            notifyItemSold(itemName);
        }
        std::cout << "[SalesFacade] Custom order finalized and paid." << std::endl;
        return order;
    } else {
        // Payment failed, we must delete the order
        std::cout << "[SalesFacade] Custom order failed: Payment declined." << std::endl;
        delete order;
        return nullptr;
    }
}







/**
 * @brief Creative Function: Processes a return.
 * @details This function assumes Order.h now has a method:
 * 'const std::vector<StockItem>& getItems() const'
 * @param order The order to be returned.
 * @return bool True if the return was successful.
 */
bool SalesFacade::processReturn(Order* order) {
    if (order == nullptr || order->getOrderStatus() != "Paid") {
        std::cout << "[SalesFacade] Return failed: Order is null or was not paid for." << std::endl;
        return false; // Can't return a non-paid or null order
    }

    // 1. Mock refund
    double amount = order->calculateTotal();
    std::cout << "[SalesFacade] Processing refund of $" << amount << "..." << std::endl;
    // In a real app, we'd call paymentProcessor->issueRefund(amount)

    // 2. Update order status
    order->setOrderStatus("Refunded");

    // 3. Return items to stock
    std::cout << "[SalesFacade] Restocking items..." << std::endl;

    // Iterate over the COPIES of items in the order
    for (const StockItem& itemCopy : order->getItems()) {

        const std::string& itemName = itemCopy.getname();
        const bool plantStock = isPlantStock(itemName);
        PlantInstance* plant = plantStock ? inventory->createPlantInstance(itemName) : nullptr;
        StockItem* newItem = new StockItem(itemName, itemCopy.getPrice(), plant);

        // Give the new item to the inventory
        inventory->additem(newItem);
    }

    std::cout << "[SalesFacade] Return processed and items restocked." << std::endl;
    return true;
}

void SalesFacade::notifyItemSold(const std::string& itemName) {
    for (Customer* customer : customers) {
        if (customer != nullptr) {
            customer->notifyItemSold(itemName);
        }
    }
}

void SalesFacade::syncInventoryContext() {
    if (inventory != nullptr) {
        inventory->setGreenhouseRoot(greenhouseRoot);
        inventory->setPlantRegistry(plantRegistry);
    }
}

bool SalesFacade::isPlantStock(const std::string& name) const {
    if (registeredManualPlants.count(name) > 0U) {
        return true;
    }
    return inventory != nullptr && inventory->isPlantType(name);
}
