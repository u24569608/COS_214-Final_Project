#include <iostream>
#include <vector>
#include <string>

// --- Include the code we want to test ---
#include "../include/Order.h"
#include "../include/OrderBuilder.h"
#include "../include/CustomOrderBuilder.h"
#include "../include/OrderDirector.h"
#include "../include/StockItem.h"
#include "../include/PlantInstance.h"

// --- Global failure counter ---
static int failures = 0;

// --- Assertion functions (copy-pasted) ---
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

// --- Our Individual Test Cases ---

void testCustomBuilder() {
    std::cout << "Running test: testCustomBuilder..." << std::endl;
    
    // ARRANGE
    CustomOrderBuilder builder;
    StockItem item1("Test Item 1", 10, nullptr);
    StockItem item2("Test Item 2", 25, nullptr);
    
    // ACT
    builder.addItem(&item1);
    builder.addItem(&item2);
    Order* order = builder.getOrder();
    
    // ASSERT
    ASSERT_TRUE(order != nullptr, "Builder should return a valid order");
    // Note: StockItem::getPrice() returns int, so 10+25=35
    ASSERT_EQ_INT((int)order->calculateTotal(), 35, "Custom order total is incorrect");
    
    delete order;
}

void testDirectorBuildsBeginnerSet() {
    std::cout << "Running test: testDirectorBuildsBeginnerSet..." << std::endl;

    // ARRANGE
    OrderDirector director;

    // ACT
    director.setBuilder(); // Director creates its own builder
    director.buildBeginnerSet();
    Order* order = director.getOrder();

    // ASSERT
    ASSERT_TRUE(order != nullptr, "Director should return a valid order");
    // 12 (Spade) + 7 (Soil) + 5 (Pot) = 24
    ASSERT_EQ_INT((int)order->calculateTotal(), 24, "Beginner Set total is incorrect");

    delete order;
}

void testDirectorBuildsGiftBasket() {
    std::cout << "Running test: testDirectorBuildsGiftBasket..." << std::endl;

    // ARRANGE
    OrderDirector director;

    // ACT
    director.setBuilder();
    director.buildGiftBasket();
    Order* order = director.getOrder();

    // ASSERT
    ASSERT_TRUE(order != nullptr, "Director should return a valid order");
    // 5 (Pot) + 10 (Rose) + 2 (Ribbon) = 17
    ASSERT_EQ_INT((int)order->calculateTotal(), 17, "Gift Basket total is incorrect");

    delete order;
}

// --- Test Runner MAIN ---
int main() {
    std::cout << "== Builder Pattern UNIT TESTS ==" << std::endl;

    testCustomBuilder();
    testDirectorBuildsBeginnerSet();
    testDirectorBuildsGiftBasket();

    // --- Print Summary ---
    if (failures == 0) {
        std::cout << "\n[PASS] All builder unit tests passed." << std::endl;
        return 0; // Exit with 0 for SUCCESS
    } else {
        std::cerr << "\n[FAIL] " << failures << " test(s) failed." << std::endl;
        return 1; // Exit with 1 for FAILURE
    }
}