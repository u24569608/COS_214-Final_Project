/**
 * @file composite_test.cpp
 * @brief Tests the greenhouse composite tree structure with custom checks.
 */
#include <iostream>
#include <string>

#include "../include/GreenhouseBed.h"

// --- Helper function for our tests ---
bool checkTest(bool condition, const std::string& testName) {
    if (!condition) {
        std::cerr << "--- FAILED: " << testName << std::endl;
        return false;
    }
    return true;
}

class MockComponent : public GreenhouseComponent {
public:
    MockComponent() : GreenhouseComponent("Mock Component"), cared(false) {}

    void performCare() override {
        cared = true;
    }

    bool cared;
};

// --- Individual test cases ---

bool testAddAndRemoveChild() {
    std::cout << "Running test: testAddAndRemoveChild..." << std::endl;
    bool passed = true;

    GreenhouseBed root("Root Bed");
    auto child = std::make_unique<GreenhouseBed>("Child Bed");
    GreenhouseBed* childPtr = child.get();

    passed &= checkTest(root.getSize() == 0, "Initial bed size should be zero");

    root.add(std::move(child));
    passed &= checkTest(root.getSize() == 1, "Size should be one after add");
    passed &= checkTest(root.findPlantInBed("Child Bed") == childPtr,
                        "findPlantInBed should locate child bed");

    // Duplicate add should be ignored
    root.add(childPtr);
    passed &= checkTest(root.getSize() == 1, "Duplicate add should not change size");

    root.remove(childPtr);
    passed &= checkTest(root.getSize() == 0, "Size should return to zero after remove");

    GreenhouseBed missing("Missing Bed");
    root.remove(&missing); // Removing non-existent child should not crash
    passed &= checkTest(root.getSize() == 0, "Removing missing child keeps size zero");

    return passed;
}

bool testPerformCareCascades() {
    std::cout << "Running test: testPerformCareCascades..." << std::endl;
    bool passed = true;

    GreenhouseBed bed("Care Bed");
    auto mockChild = std::make_unique<MockComponent>();
    MockComponent* childPtr = mockChild.get();

    bed.add(std::move(mockChild));
    bed.performCare();

    passed &= checkTest(childPtr->cared, "Child component should be cared for");

    return passed;
}

bool testFindPlantInNestedBeds() {
    std::cout << "Running test: testFindPlantInNestedBeds..." << std::endl;
    bool passed = true;

    GreenhouseBed root("Root");
    auto inner = std::make_unique<GreenhouseBed>("Inner");
    auto leafHolder = std::make_unique<GreenhouseBed>("Leaf Holder");
    GreenhouseBed* innerPtr = inner.get();

    root.add(std::move(leafHolder));
    root.add(std::move(inner));

    // TODO: Replace with iterator-based traversal when available.
    GreenhouseComponent* found = root.findPlantInBed("Inner");
    passed &= checkTest(found == innerPtr, "findPlantInBed should locate nested bed");

    return passed;
}

// --- Test runner ---
int main() {
    int testsPassed = 0;
    int testsTotal = 0;

    if (testAddAndRemoveChild()) testsPassed++;
    testsTotal++;

    if (testPerformCareCascades()) testsPassed++;
    testsTotal++;

    if (testFindPlantInNestedBeds()) testsPassed++;
    testsTotal++;

    std::cout << "\n---------------------------\n";
    std::cout << "     TEST SUMMARY          \n";
    std::cout << " Tests Passed: " << testsPassed << " / " << testsTotal << std::endl;
    std::cout << "---------------------------\n";

    return (testsPassed == testsTotal) ? 0 : 1;
}
