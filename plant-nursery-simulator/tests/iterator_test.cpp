#include <iostream>
#include <vector>
#include <string>
#include <memory>

// --- Include the code we want to test ---
#include "../include/Inventory.h"
#include "../include/InventoryIterator.h"
#include "../include/ConcreteInventoryIterator.h"
#include "../include/StockItem.h"
#include "../include/PlantInstance.h"

// --- Global failure counter ---
static int failures = 0;

// --- Assertion functions (copy-pasted from builder_test.cpp) ---
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


// --- Our Individual Test Cases (now void) ---

/**
 * @brief Tests how the iterator behaves on an empty inventory.
 */
void testEmptyInventory() {
    std::cout << "Running test: testEmptyInventory..." << std::endl;

    // ARRANGE
    Inventory inv;

    // ACT
    InventoryIterator* iter = inv.createIterator();

    // ASSERT
    ASSERT_TRUE(iter->hasNext() == false, "hasNext() should be false");
    ASSERT_TRUE(iter->currentItem() == nullptr, "currentItem() should be nullptr");
    ASSERT_TRUE(iter->first() == nullptr, "first() should be nullptr");
    ASSERT_TRUE(iter->next() == nullptr, "next() should be nullptr");

    delete iter;
}

/**
 * @brief Tests a standard traversal from beginning to end.
 */
void testStandardTraversal() {
    std::cout << "Running test: testStandardTraversal..." << std::endl;

    // ARRANGE
    Inventory inv;
    inv.additem(std::make_unique<StockItem>("Monstera", 25.0, nullptr));
    inv.additem(std::make_unique<StockItem>("Fiddle Fig", 45.0, nullptr));
    inv.additem(std::make_unique<StockItem>("Soil", 10.0, nullptr));

    std::vector<std::string> expectedNames = {"Monstera", "Fiddle Fig", "Soil"};
    int index = 0; // index remains int

    InventoryIterator* iter = inv.createIterator();

    // ACT & ASSERT
    for (iter->first(); iter->hasNext(); /* We call next() inside the loop */) {
        StockItem* item = iter->currentItem();

        ASSERT_TRUE(item != nullptr, "currentItem() should not be null during traversal");

        // Cast index to size_t for comparison here to fix the warning
        if (static_cast<size_t>(index) >= expectedNames.size()) {
            ASSERT_TRUE(false, "Iterator ran more times than expected");
            break;
        }

        // This now works with the 'const' getname()
        ASSERT_EQ_STR(item->getname(), expectedNames[index],
                      "Item name mismatch at index " + std::to_string(index));

        index++;
        item = iter->next(); // Call next() at the end to advance
        // If next() returns nullptr, hasNext() will be false next iteration
    }

    // After the loop, currentItem() might be the last valid item or nullptr
    // Check that we visited the correct number of items
    ASSERT_EQ_INT(index, 3, "Iterator did not visit all items");
    // hasNext() should definitely be false after visiting the last item
    ASSERT_TRUE(iter->hasNext() == false, "hasNext() should be false after loop");


    delete iter;
}

/**
 * @brief Tests if the iterator can be reset mid-traversal.
 */
void testResetIterator() {
    std::cout << "Running test: testResetIterator..." << std::endl;

    // ARRANGE
    Inventory inv;
    inv.additem(std::make_unique<StockItem>("Item A", 1.0, nullptr));
    inv.additem(std::make_unique<StockItem>("Item B", 2.0, nullptr));

    InventoryIterator* iter = inv.createIterator();

    // ACT & ASSERT (Part 1: Move forward)
    iter->first();
    ASSERT_EQ_STR(iter->currentItem()->getname(), "Item A", "first() did not get Item A");

    iter->next();
    ASSERT_EQ_STR(iter->currentItem()->getname(), "Item B", "next() did not get Item B");

    // ACT & ASSERT (Part 2: Reset)
    iter->reset();

    ASSERT_TRUE(iter->hasNext() == true, "hasNext() is false after reset");
    ASSERT_TRUE(iter->currentItem() != nullptr, "currentItem() is null after reset");
    ASSERT_EQ_STR(iter->currentItem()->getname(), "Item A", "reset() did not return to Item A");

    delete iter;
}


// --- Our Test Runner MAIN Function (now matches builder_test) ---

int main() {
    std::cout << "== Iterator Basic UNIT TESTS ==" << std::endl;

    // Run all test functions
    testEmptyInventory();
    testStandardTraversal();
    testResetIterator();

    // --- Print Summary ---
    if (failures == 0) {
        std::cout << "\n[PASS] All iterator unit tests passed." << std::endl;
        return 0; // Exit with 0 for SUCCESS
    } else {
        std::cerr << "\n[FAIL] " << failures << " test(s) failed." << std::endl;
        return 1; // Exit with 1 for FAILURE
    }
}
