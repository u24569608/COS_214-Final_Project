#include <iostream>
#include <memory>
#include <string>
#include <vector>

// --- Include the code we want to test ---
#include "../include/SalesFacade.h"
#include "../include/Inventory.h"
#include "../include/PaymentProcessor.h"
#include "../include/OrderBuilder.h"
#include "../include/CustomOrderBuilder.h" // Need the concrete builder
#include "../include/Order.h"
#include "../include/StockItem.h"
#include "../include/PlantInstance.h" // For stubs
#include "../include/InventoryIterator.h"
#include "../include/ConcreteInventoryIterator.h"
#include "../include/GreenhouseBed.h"
#include "../include/PlantPrototypeRegistry.h"
#include "../include/Plant.h"
#include "../include/Customer.h"

// --- Global failure counter ---
static int failures = 0;

// --- Assertion functions (copy-pasted from other tests) ---
void ASSERT_TRUE(bool expr, const std::string& msg) {
    if (expr == false) {
        std::cerr << "[ASSERT_TRUE FAILED] " << msg << std::endl;
        failures = failures + 1;
    }
}
void ASSERT_EQ_INT(int a, int b, const std::string& msg) {
    if (a == b) { return; }
    std::cerr << "[ASSERT_EQ_INT FAILED] " << msg
              << " (expected " << b << ", got " << a << ")"
              << std::endl;
    failures = failures + 1;
}
void ASSERT_EQ_STR(const std::string& a, const std::string& b, const std::string& msg) {
    if (a == b) { return; }
    std::cerr << "[ASSERT_EQ_STR FAILED] " << msg
              << " (expected \"" << b << "\", got \"" << a << "\")"
              << std::endl;
    failures = failures + 1;
}

// --- Test scaffolding ---
class StubPlant : public Plant {
public:
    StubPlant() = default;
    explicit StubPlant(const std::string& displayName) {
        setName(displayName);
    }
    Plant* clone() const override {
        return new StubPlant(*this);
    }
};

void registerPrototype(const std::string& name, PlantPrototypeRegistry& reg) {
    auto plant = std::make_unique<StubPlant>(name);
    reg.addPrototype(name, std::move(plant));
}

SalesFacade* facade = nullptr;
Inventory* inv = nullptr;
PaymentProcessor* pp = nullptr;
OrderBuilder* ob = nullptr;
GreenhouseBed* greenhouse = nullptr;
std::unique_ptr<PlantPrototypeRegistry> registry;

void clearInventory() {
    if (!inv) {
        return;
    }
    std::unique_ptr<InventoryIterator> iter(inv->createIterator());
    if (!iter) {
        return;
    }
    std::vector<std::string> names;
    for (StockItem* item = iter->first(); item != nullptr; item = iter->next()) {
        if (item != nullptr) {
            names.push_back(item->getname());
        }
    }
    for (const std::string& name : names) {
        inv->removeItem(name);
    }
}


// --- Our Test Cases ---

void testStockCheckAndAdd() {
    std::cout << "Running test: testStockCheckAndAdd..." << std::endl;
    clearInventory();
    const int greenhouseBefore = greenhouse->getSize();
    facade->registerPlantType("Rose");
    ASSERT_EQ_INT(facade->checkStock("Rose"), 0, "Stock should be 0");

    facade->addItemToInventory("Rose", 15.0);

    ASSERT_EQ_INT(facade->checkStock("Rose"), 1, "Stock should be 1 after add");
    ASSERT_EQ_INT(greenhouse->getSize(), greenhouseBefore + 1, "Greenhouse should gain one plant");
    clearInventory();
}

void testPurchaseHappyPath() {
    std::cout << "Running test: testPurchaseHappyPath..." << std::endl;
    clearInventory();
    facade->registerPlantType("Tulip");
    facade->addItemToInventory("Tulip", 5.0);
    StockItem* tulip = inv->findItem("Tulip"); // Get the real item from inventory
    ASSERT_TRUE(tulip != nullptr && tulip->getplant() != nullptr, "Tulip should link to a plant instance");
    const int greenhouseBeforePurchase = greenhouse->getSize();

    bool success = facade->purchaseItem(nullptr, tulip);

    ASSERT_TRUE(success, "Purchase should be successful");
    ASSERT_EQ_INT(facade->checkStock("Tulip"), 0, "Tulip should be removed from stock");
    ASSERT_EQ_INT(greenhouse->getSize(), greenhouseBeforePurchase - 1, "Greenhouse should release the sold plant");
}

void testPurchaseInsufficientStock() {
    std::cout << "Running test: testPurchaseInsufficientStock..." << std::endl;
    clearInventory();
    ASSERT_EQ_INT(facade->checkStock("Venus Flytrap"), 0, "Item should not be in stock");
    StockItem* flytrap = new StockItem("Venus Flytrap", 30.0, nullptr);

    bool success = facade->purchaseItem(nullptr, flytrap);

    ASSERT_TRUE(success == false, "Purchase should fail for out-of-stock item");
    delete flytrap; // Clean up our fake item
}

void testBuildAndFinalizeOrder() {
    std::cout << "Running test: testBuildAndFinalizeOrder..." << std::endl;
    clearInventory();
    const int greenhouseBefore = greenhouse->getSize();

    facade->addItemToInventory("Soil", 10.0, false);
    facade->addItemToInventory("Pot", 5.0, false);

    StockItem item1("Soil", 10.0, nullptr);
    StockItem item2("Pot", 5.0, nullptr);
    std::vector<StockItem> items = {item1, item2};

    Order* order = facade->buildAndFinalizeOrder(nullptr, items);

    ASSERT_TRUE(order != nullptr, "Order should be created and returned");
    ASSERT_EQ_STR(order->getOrderStatus(), "Paid", "Order status should be 'Paid'");
    ASSERT_EQ_INT(static_cast<int>(order->calculateTotal()), 15, "Order total should be 15");
    ASSERT_EQ_INT(facade->checkStock("Soil"), 0, "Soil should be removed from stock");
    ASSERT_EQ_INT(facade->checkStock("Pot"), 0, "Pot should be removed from stock");
    ASSERT_EQ_INT(greenhouse->getSize(), greenhouseBefore, "Supplies should not affect greenhouse plants");

    delete order;
    clearInventory();
}

void testProcessReturn() {
    std::cout << "Running test: testProcessReturn..." << std::endl;
    clearInventory();
    facade->registerPlantType("Orchid");
    facade->addItemToInventory("Orchid", 25.0);
    ASSERT_EQ_INT(facade->checkStock("Orchid"), 1, "Orchid should be in stock");

    StockItem item1("Orchid", 25.0, nullptr);
    std::vector<StockItem> items = {item1};
    Order* order = facade->buildAndFinalizeOrder(nullptr, items);

    ASSERT_TRUE(order != nullptr, "Order should have been created");
    ASSERT_EQ_STR(order->getOrderStatus(), "Paid", "Order should be 'Paid'");
    ASSERT_EQ_INT(facade->checkStock("Orchid"), 0, "Orchid should be sold out");
    const int greenhouseAfterSale = greenhouse->getSize();

    bool success = facade->processReturn(order);

    ASSERT_TRUE(success, "Return should be successful");
    ASSERT_EQ_STR(order->getOrderStatus(), "Refunded", "Order status should be 'Refunded'");
    ASSERT_EQ_INT(facade->checkStock("Orchid"), 1, "Orchid should be restocked");
    ASSERT_EQ_INT(greenhouse->getSize(), greenhouseAfterSale + 1, "Greenhouse should receive the returned plant");

    delete order;
    clearInventory();
}

void testCustomerCartSync() {
    std::cout << "Running test: testCustomerCartSync..." << std::endl;
    clearInventory();
    facade->registerPlantType("Lily");
    facade->addItemToInventory("Lily", 18.0);
    StockItem* lily = inv->findItem("Lily");
    ASSERT_TRUE(lily != nullptr, "Lily should exist in inventory");

    Customer alice(1, nullptr);
    Customer bob(2, nullptr);
    ASSERT_TRUE(facade->addItemToCart(&alice, "Lily"), "Facade should add Lily to Alice's cart");
    ASSERT_TRUE(facade->addItemToCart(&bob, "Lily"), "Facade should add Lily to Bob's cart");

    bool success = facade->purchaseItem(&alice, lily);
    ASSERT_TRUE(success, "Customer purchase should succeed");
    ASSERT_EQ_INT(static_cast<int>(alice.getCartSize()), 0, "Purchasing customer cart should be cleared");
    ASSERT_EQ_INT(static_cast<int>(bob.getCartSize()), 0, "Other customer cart should remove sold item");

    facade->unregisterCustomer(&alice);
    facade->unregisterCustomer(&bob);
}

void testDefaultPrototypeRegistration() {
    std::cout << "Running test: testDefaultPrototypeRegistration..." << std::endl;
    clearInventory();
    const std::string newPlant = "Aloe";
    ASSERT_TRUE(!registry->hasPrototype(newPlant), "Registry should not have Aloe before registration");

    facade->registerPlantType(newPlant);
    ASSERT_TRUE(registry->hasPrototype(newPlant), "Facade should register default prototype when none exists");

    facade->addItemToInventory(newPlant, 22.0);
    StockItem* aloe = inv->findItem(newPlant);
    ASSERT_TRUE(aloe != nullptr && aloe->getplant() != nullptr, "Aloe stock should include a plant instance");

    bool success = facade->purchaseItem(nullptr, aloe);
    ASSERT_TRUE(success, "Anonymous purchase should succeed");
    ASSERT_EQ_INT(facade->checkStock(newPlant), 0, "Purchasing Aloe should remove it from stock");
}

// --- Test Runner MAIN ---
int main() {
    std::cout << "== Facade Pattern UNIT TESTS ==" << std::endl;
    
    // --- ARRANGE (Global) ---
    inv = new Inventory();
    pp = new PaymentProcessor();
    ob = new CustomOrderBuilder();
    greenhouse = new GreenhouseBed("Unit Test Greenhouse");
    registry = std::make_unique<PlantPrototypeRegistry>();
    registerPrototype("Rose", *registry);
    registerPrototype("Tulip", *registry);
    registerPrototype("Orchid", *registry);
    registerPrototype("Lily", *registry);
    facade = new SalesFacade(inv, pp, ob, greenhouse, registry.get());

    // --- ACT & ASSERT ---
    testStockCheckAndAdd();
    testPurchaseHappyPath();
    testPurchaseInsufficientStock();
    testBuildAndFinalizeOrder();
    testProcessReturn();
    testCustomerCartSync();
    testDefaultPrototypeRegistration();

    // --- CLEANUP ---
    delete facade;
    delete inv;
    delete pp;
    delete ob;
    delete greenhouse;
    registry.reset();

    // --- Print Summary ---
    if (failures == 0) {
        std::cout << "\n[PASS] All facade unit tests passed." << std::endl;
        return 0; // Exit with 0 for SUCCESS
    } else {
        std::cerr << "\n[FAIL] " << failures << " test(s) failed." << std::endl;
        return 1; // Exit with 1 for FAILURE
    }
}
