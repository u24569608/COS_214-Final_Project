#include <iostream>
#include <vector>
#include <string>

// --- Include the code we want to test ---
// We need to be ableto access the classes we're testing.
// The paths might be different depending on your folder structure.
#include "../include/Inventory.h"
#include "../include/InventoryIterator.h"
#include "../include/ConcreteInventoryIterator.h"
#include "../include/StockItem.h"
#include "../include/PlantInstance.h"

// --- Helper function for our tests ---
// A simple "Assert" function
// It checks if a condition is true. If not, it prints an error.
bool checkTest(bool condition, const std::string& testName) {
    if (!condition) {
        std::cerr << "--- FAILED: " << testName << std::endl;
        return false;
    }
    return true;
}

// --- Our Individual Test Cases ---

/**
 * @brief Tests how the iterator behaves on an empty inventory.
 */
bool testEmptyInventory() {
    std::cout << "Running test: testEmptyInventory..." << std::endl;
    bool passed = true;

    // ARRANGE
    Inventory inv;

    // ACT
    InventoryIterator* iter = inv.createIterator();

    // ASSERT
    // hasNext() should be false immediately
    passed &= checkTest(iter->hasNext() == false, "hasNext() should be false");
    
    // currentItem() should return nothing
    passed &= checkTest(iter->currentItem() == nullptr, "currentItem() should be nullptr");
    
    // first() should also return nothing and not crash
    passed &= checkTest(iter->first() == nullptr, "first() should be nullptr");
    
    // next() should return nothing and not crash
    passed &= checkTest(iter->next() == nullptr, "next() should be nullptr");

    delete iter;
    // 'inv' is automatically destroyed
    return passed;
}

/**
 * @brief Tests a standard traversal from beginning to end.
 */
bool testStandardTraversal() {
    std::cout << "Running test: testStandardTraversal..." << std::endl;
    bool passed = true;
    
    // ARRANGE
    Inventory inv;
    inv.additem(new StockItem("Monstera", 25.0, nullptr));
    inv.additem(new StockItem("Fiddle Fig", 45.0, nullptr));
    inv.additem(new StockItem("Soil", 10.0, nullptr));
    
    // A list of the names we expect, in order
    std::vector<std::string> expectedNames = {"Monstera", "Fiddle Fig", "Soil"};
    int index = 0;

    InventoryIterator* iter = inv.createIterator();

    // ACT & ASSERT
    // We'll loop using the iterator and check each item
    for (iter->first(); iter->hasNext(); iter->next()) {
        StockItem* item = iter->currentItem();

        // Check that the item exists
        passed &= checkTest(item != nullptr, "currentItem() should not be null during traversal");
        
        // Check that we're not running past the end of our expected list
        passed &= checkTest(index < expectedNames.size(), "Iterator ran too many times");
        if (index >= expectedNames.size()) break; // Prevent crash

        // Check that the item name is what we expect
        passed &= checkTest(item->getname() == expectedNames[index], 
                          "Item name mismatch. Expected: " + expectedNames[index] + 
                          ", Got: " + item->getname());
        
        index++;
    }
    
    // Final check: Did the iterator stop at the right time?
    passed &= checkTest(index == expectedNames.size(), "Iterator did not visit all items");
    // After the loop, hasNext() should be false
    passed &= checkTest(iter->hasNext() == false, "hasNext() should be false after loop");
    // And currentItem() should be null
    passed &= checkTest(iter->currentItem() == nullptr, "currentItem() should be null after loop");


    delete iter;
    return passed;
}

/**
 * @brief Tests if the iterator can be reset mid-traversal.
 */
bool testResetIterator() {
    std::cout << "Running test: testResetIterator..." << std::endl;
    bool passed = true;

    // ARRANGE
    Inventory inv;
    inv.additem(new StockItem("Item A", 1.0, nullptr));
    inv.additem(new StockItem("Item B", 2.0, nullptr));
    
    InventoryIterator* iter = inv.createIterator();

    // ACT & ASSERT (Part 1: Move forward)
    iter->first();
    passed &= checkTest(iter->currentItem()->getname() == "Item A", "first() did not get Item A");
    
    iter->next();
    passed &= checkTest(iter->currentItem()->getname() == "Item B", "next() did not get Item B");

    // ACT & ASSERT (Part 2: Reset)
    iter->reset(); // Your spec had a reset() method in the interface
    
    // After reset, we should be back at the beginning
    passed &= checkTest(iter->hasNext() == true, "hasNext() is false after reset");
    passed &= checkTest(iter->currentItem() != nullptr, "currentItem() is null after reset");
    passed &= checkTest(iter->currentItem()->getname() == "Item A", "reset() did not return to Item A");

    delete iter;
    return passed;
}


// --- Our Test Runner MAIN Function ---

int main() {
    int testsPassed = 0;
    int testsTotal = 0;

    // Run all test functions
    if (testEmptyInventory()) testsPassed++;
    testsTotal++;
    
    if (testStandardTraversal()) testsPassed++;
    testsTotal++;

    if (testResetIterator()) testsPassed++;
    testsTotal++;

    // --- Print Summary ---
    std::cout << "\n---------------------------\n";
    std::cout << "     TEST SUMMARY          \n";
    std::cout << " Tests Passed: " << testsPassed << " / " << testsTotal << std::endl;
    std::cout << "---------------------------\n";

    // Return a 0 code if all tests passed, and 1 if any failed
    // This is good practice for automation
    return (testsPassed == testsTotal) ? 0 : 1;
}