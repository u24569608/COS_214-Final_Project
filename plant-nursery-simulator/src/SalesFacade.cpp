/**
 * @file SalesFacade.cpp
 * @brief Implements the SalesFacade behaviour defined in the corresponding header.
 */

#include "../include/SalesFacade.h"
#include "../include/Inventory.h"
#include "../include/PaymentProcessor.h"
#include "../include/OrderBuilder.h"
#include "../include/Order.h"
#include "../include/StockItem.h"
#include "../include/Customer.h" // Needed for method signatures
#include "../include/GreenhouseBed.h"
#include "../include/PlantPrototypeRegistry.h"
#include "../include/Plant.h"
#include "../include/FrequentWatering.h"
#include "../include/SparseWatering.h"
#include "../include/SeasonalWatering.h"
#include "../include/OrganicFertilizer.h"
#include "../include/LiquidFertilizer.h"
#include "../include/SlowReleaseFertilizer.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <memory>
#include <string>

namespace {
std::string toLower(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
                   [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    return value;
}

WaterStrategy& frequentWatering() {
    static FrequentWatering strategy;
    return strategy;
}

WaterStrategy& sparseWatering() {
    static SparseWatering strategy;
    return strategy;
}

WaterStrategy& seasonalWatering() {
    static SeasonalWatering strategy;
    return strategy;
}

FertilizeStrategy& organicFertilizer() {
    static OrganicFertilizer strategy;
    return strategy;
}

FertilizeStrategy& slowReleaseFertilizer() {
    static SlowReleaseFertilizer strategy;
    return strategy;
}

FertilizeStrategy& liquidFertilizer() {
    static LiquidFertilizer strategy;
    return strategy;
}

WaterStrategy& selectWaterStrategy(const std::string& plantName) {
    const std::string lowered = toLower(plantName);
    if (lowered.find("cactus") != std::string::npos ||
        lowered.find("succulent") != std::string::npos) {
        return sparseWatering();
    }
    if (lowered.find("fern") != std::string::npos ||
        lowered.find("orchid") != std::string::npos) {
        return frequentWatering();
    }
    return seasonalWatering();
}

FertilizeStrategy& selectFertilizeStrategy(const std::string& plantName) {
    const std::string lowered = toLower(plantName);
    if (lowered.find("bonsai") != std::string::npos ||
        lowered.find("orchid") != std::string::npos) {
        return liquidFertilizer();
    }
    if (lowered.find("cactus") != std::string::npos ||
        lowered.find("succulent") != std::string::npos) {
        return slowReleaseFertilizer();
    }
    return organicFertilizer();
}

class DefaultPlantPrototype final : public Plant {
public:
    DefaultPlantPrototype(const std::string& displayName,
                          WaterStrategy& waterStrategy,
                          FertilizeStrategy& fertilizeStrategy) {
        setName(displayName);
        setType("Retail Plant");
        setDefaultWaterStrat(&waterStrategy);
        setDefaultFertStrat(&fertilizeStrategy);
    }

    Plant* clone() const override {
        return new DefaultPlantPrototype(*this);
    }
};

std::unique_ptr<Plant> makeDefaultPrototype(const std::string& plantName) {
    return std::make_unique<DefaultPlantPrototype>(
        plantName,
        selectWaterStrategy(plantName),
        selectFertilizeStrategy(plantName));
}
} // namespace

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
    ensurePrototypeRegistered(name);
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
        inventory->additem(std::make_unique<StockItem>(name, price, plant));
    } else {
        inventory->additem(std::make_unique<StockItem>(name, price, nullptr));
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
    StockItem* itemInStock = inventory->findItemById(item->getId());
    if (itemInStock == nullptr) {
        itemInStock = inventory->findItem(itemName);
    }

    if (itemInStock == nullptr) {
        std::cout << "[SalesFacade] Purchase failed: " << itemName << " is out of stock." << std::endl;
        return false; // Insufficient stock
    }
    const std::string itemId = itemInStock->getId();

    if (customer != nullptr) {
        customer->removeFromCartById(itemId);
    }

    // 2. Process Payment
    // Using const getter now
    double price = itemInStock->getPrice();
    // In a real app, we'd get customer details from the Customer object
    bool paid = paymentProcessor->processPayment("MockCustomerDetails", price);

    // 3. Update Inventory
    if (paid) {
        const bool removed = inventory->removeItemById(itemId);
        if (!removed) {
            std::cerr << "[SalesFacade] Purchase failed: Unable to remove " << itemName
                      << " from inventory.\n";
            return false;
        }
        notifyItemSold(itemId, itemName);
        std::cout << "[SalesFacade] Purchase of " << itemName << " complete." << std::endl;
        return true;
    }

    std::cout << "[SalesFacade] Purchase failed: Payment declined." << std::endl;
    return false;
}

bool SalesFacade::addItemToCart(Customer* customer, const std::string& itemName) {
    if (customer == nullptr || inventory == nullptr) {
        return false;
    }

    registerCustomer(customer);

    StockItem* item = inventory->findItem(itemName);
    if (item == nullptr) {
        std::cout << "[SalesFacade] Cannot add '" << itemName << "' to cart: item not found.\n";
        return false;
    }

    customer->addToCart(item);
    return true;
}

/**
 * @brief Simplifies building a complex order.
 */
bool SalesFacade::buildAndFinalizeOrder(Customer* customer, Order& order) {
    if (!inventory || !paymentProcessor) {
        return false;
    }

    const std::vector<StockItem>& items = order.getItems();
    if (items.empty()) {
        std::cout << "[SalesFacade] Custom order aborted: no items to process." << std::endl;
        return false;
    }

    const double total = order.calculateTotal();
    if (!paymentProcessor->processPayment("MockCustomerDetails", total)) {
        std::cout << "[SalesFacade] Custom order failed: Payment declined." << std::endl;
        return false;
    }

    order.setOrderStatus("Paid");

    for (const StockItem& item : items) {
        std::string itemId = item.getId();
        std::string itemName = item.getname();

        StockItem* inventoryItem = nullptr;
        if (!itemId.empty()) {
            inventoryItem = inventory->findItemById(itemId);
        }
        if (!inventoryItem && !itemName.empty()) {
            inventoryItem = inventory->findItem(itemName);
            if (inventoryItem != nullptr) {
                itemId = inventoryItem->getId();
                itemName = inventoryItem->getname();
            }
        }

        if (customer != nullptr) {
            if (!itemId.empty()) {
                customer->removeFromCartById(itemId);
            } else if (!itemName.empty()) {
                customer->removeFromCart(itemName);
            }
        }

        bool removed = false;
        if (!itemId.empty()) {
            removed = inventory->removeItemById(itemId);
        } else if (!itemName.empty()) {
            const int countBefore = inventory->getStockCount(itemName);
            inventory->removeItem(itemName);
            removed = countBefore > inventory->getStockCount(itemName);
        }

        if (removed) {
            notifyItemSold(itemId, itemName);
        } else {
            std::cerr << "[SalesFacade] Warning: Unable to retire '" << itemName
                      << "' while finalising order.\n";
        }
    }

    std::cout << "[SalesFacade] Custom order finalized and paid." << std::endl;
    return true;
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
        auto newItem = std::make_unique<StockItem>(itemName, itemCopy.getPrice(), plant);
        inventory->additem(std::move(newItem));
    }

    std::cout << "[SalesFacade] Return processed and items restocked." << std::endl;
    return true;
}

void SalesFacade::notifyItemSold(const std::string& itemId, const std::string& itemName) {
    for (Customer* customer : customers) {
        if (customer != nullptr) {
            customer->notifyItemSold(itemId, itemName);
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

void SalesFacade::ensurePrototypeRegistered(const std::string& name) {
    if (plantRegistry == nullptr || name.empty()) {
        return;
    }
    if (plantRegistry->hasPrototype(name)) {
        return;
    }
    plantRegistry->addPrototype(name, makeDefaultPrototype(name));
}
