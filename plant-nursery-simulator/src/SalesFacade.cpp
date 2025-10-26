#include "../include/SalesFacade.h"
#include "../include/Inventory.h"
#include "../include/PaymentProcessor.h"
#include "../include/OrderBuilder.h"
#include "../include/Order.h"
#include "../include/StockItem.h"
#include "../include/Customer.h" // Needed for method signatures
#include <iostream>

/**
 * @brief Constructor that "wires" the facade to its subsystems.
 */
SalesFacade::SalesFacade(Inventory* inv, PaymentProcessor* pp, OrderBuilder* ob)
    : inventory(inv), paymentProcessor(pp), orderBuilder(ob) {
    // All subsystems are now linked
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
void SalesFacade::addItemToInventory(std::string name, double price) {
    // We use the stub StockItem constructor
    StockItem* newItem = new StockItem(name, price, nullptr);
    inventory->additem(newItem);
    std::cout << "[SalesFacade] Added " << name << " to inventory." << std::endl;
}

/**
 * @brief Simplifies buying a single item.
 * This is the "happy path" (browse->add->pay).
 */
bool SalesFacade::purchaseItem(Customer* customer, StockItem* item) {
    (void)customer; // <-- ADD THIS LINE to silence the unused parameter warning
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

    // 2. Process Payment
    // Using const getter now
    double price = itemInStock->getPrice();
    // In a real app, we'd get customer details from the Customer object
    // For now, using a mock string since 'customer' is unused
    bool paid = paymentProcessor->processPayment("MockCustomerDetails", price);

    // 3. Update Inventory
    if (paid) {
        // This removes ONE item of this name, per Inventory.h logic
        inventory->removeItem(itemName);
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
    (void)customer; // <-- ADD THIS LINE to silence the unused parameter warning
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
            inventory->removeItem(item.getname());
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

        // Create a NEW item on the heap (a "new plant")
        // We must do this because Inventory expects to OWN its pointers.
        StockItem* newItem = new StockItem(
            itemCopy.getname(),
            itemCopy.getPrice(),
            nullptr // We lose the specific PlantInstance,
                    // but the item (e.g., "Rose") is back in stock.
        );

        // Give the new item to the inventory
        inventory->additem(newItem);
    }

    std::cout << "[SalesFacade] Return processed and items restocked." << std::endl;
    return true;
}
