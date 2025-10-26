#include <iostream>
#include <vector>
#include <string>

// --- Include the code we want to test ---
#include "../include/SalesFacade.h"
#include "../include/Inventory.h"
#include "../include/PaymentProcessor.h"
#include "../include/OrderBuilder.h"
#include "../include/CustomOrderBuilder.h" // Need the concrete builder
#include "../include/Order.h"
#include "../include/StockItem.h"
#include "../include/PlantInstance.h" // For stubs
#include "../include/Subject.h" // For stubs
#include "../include/GreenhouseComponent.h" // For stubs
#include "../include/InventoryCollection.h" // For stubs
#include "../include/InventoryIterator.h" // For stubs
#include "../include/ConcreteInventoryIterator.h" // For stubs

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


// --- Our Test Cases ---
SalesFacade* facade;
Inventory* inv;
PaymentProcessor* pp;
OrderBuilder* ob;

void testStockCheckAndAdd() {
    std::cout << "Running test: testStockCheckAndAdd..." << std::endl;
    // ARRANGE
    ASSERT_EQ_INT(facade->checkStock("Rose"), 0, "Stock should be 0");
    
    // ACT
    facade->addItemToInventory("Rose", 15.0);
    
    // ASSERT
    ASSERT_EQ_INT(facade->checkStock("Rose"), 1, "Stock should be 1 after add");
}

void testPurchaseHappyPath() {
    std::cout << "Running test: testPurchaseHappyPath..." << std::endl;
    // ARRANGE
    facade->addItemToInventory("Tulip", 5.0);
    ASSERT_EQ_INT(facade->checkStock("Tulip"), 1, "Tulip should be in stock");
    StockItem* tulip = inv->findItem("Tulip"); // Get the real item from inventory
    
    // ACT
    bool success = facade->purchaseItem(nullptr, tulip);
    
    // ASSERT
    ASSERT_TRUE(success, "Purchase should be successful");
    ASSERT_EQ_INT(facade->checkStock("Tulip"), 0, "Tulip should be removed from stock");
}

void testPurchaseInsufficientStock() {
    std::cout << "Running test: testPurchaseInsufficientStock..." << std::endl;
    // ARRANGE
    ASSERT_EQ_INT(facade->checkStock("Venus Flytrap"), 0, "Item should not be in stock");
    StockItem* flytrap = new StockItem("Venus Flytrap", 30.0, nullptr);
    
    // ACT
    bool success = facade->purchaseItem(nullptr, flytrap);
    
    // ASSERT
    ASSERT_TRUE(success == false, "Purchase should fail for out-of-stock item");
    delete flytrap; // Clean up our fake item
}

void testBuildAndFinalizeOrder() {
    std::cout << "Running test: testBuildAndFinalizeOrder..." << std::endl;
    // ARRANGE
    facade->addItemToInventory("Soil", 10.0);
    facade->addItemToInventory("Pot", 5.0);
    
    StockItem item1("Soil", 10.0, nullptr);
    StockItem item2("Pot", 5.0, nullptr);
    std::vector<StockItem> items = {item1, item2};
    
    // ACT
    Order* order = facade->buildAndFinalizeOrder(nullptr, items);
    
    // ASSERT
    ASSERT_TRUE(order != nullptr, "Order should be created and returned");
    ASSERT_EQ_STR(order->getOrderStatus(), "Paid", "Order status should be 'Paid'");
    ASSERT_EQ_INT((int)order->calculateTotal(), 15, "Order total should be 15");
    ASSERT_EQ_INT(facade->checkStock("Soil"), 0, "Soil should be removed from stock");
    ASSERT_EQ_INT(facade->checkStock("Pot"), 0, "Pot should be removed from stock");
    
    delete order;
}

void testProcessReturn() {
    std::cout << "Running test: testProcessReturn..." << std::endl;
    // ARRANGE
    // 1. Add an item to inventory
    facade->addItemToInventory("Orchid", 25.0);
    ASSERT_EQ_INT(facade->checkStock("Orchid"), 1, "Orchid should be in stock");

    // 2. Create a "paid" order for that item
    StockItem item1("Orchid", 25.0, nullptr);
    std::vector<StockItem> items = {item1};
    Order* order = facade->buildAndFinalizeOrder(nullptr, items);
    
    // 3. Check that the item is GONE from stock
    ASSERT_TRUE(order != nullptr, "Order should have been created");
    ASSERT_EQ_STR(order->getOrderStatus(), "Paid", "Order should be 'Paid'");
    ASSERT_EQ_INT(facade->checkStock("Orchid"), 0, "Orchid should be sold out");

    // ACT
    // Now, process the return
    bool success = facade->processReturn(order);

    // ASSERT
    ASSERT_TRUE(success, "Return should be successful");
    ASSERT_EQ_STR(order->getOrderStatus(), "Refunded", "Order status should be 'Refunded'");
    // The item should be back in stock
    ASSERT_EQ_INT(facade->checkStock("Orchid"), 1, "Orchid should be restocked");
    
    delete order;
}

// --- Test Runner MAIN ---
int main() {
    std::cout << "== Facade Pattern UNIT TESTS ==" << std::endl;
    
    // --- ARRANGE (Global) ---
    // Create all the subsystems
    inv = new Inventory();
    pp = new PaymentProcessor();
    ob = new CustomOrderBuilder();
    // Create the Facade and wire it
    facade = new SalesFacade(inv, pp, ob);

    // --- ACT & ASSERT ---
    testStockCheckAndAdd();
    testPurchaseHappyPath();
    testPurchaseInsufficientStock();
    testBuildAndFinalizeOrder();
    testProcessReturn(); // <-- ADD THIS LINE

    // --- CLEANUP ---
    delete facade;
    delete inv;
    delete pp;
    delete ob;

    // --- Print Summary ---
    if (failures == 0) {
        std::cout << "\n[PASS] All facade unit tests passed." << std::endl;
        return 0; // Exit with 0 for SUCCESS
    } else {
        std::cerr << "\n[FAIL] " << failures << " test(s) failed." << std::endl;
        return 1; // Exit with 1 for FAILURE
    }
}