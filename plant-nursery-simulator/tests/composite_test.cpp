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
    GreenhouseBed child("Child Bed");

    passed &= checkTest(root.getSize() == 0, "Initial bed size should be zero");

    root.add(&child);
    passed &= checkTest(root.getSize() == 1, "Size should be one after add");
    passed &= checkTest(root.findPlantInBed("Child Bed") == &child,
                        "findPlantInBed should locate child bed");

    // Duplicate add should be ignored
    root.add(&child);
    passed &= checkTest(root.getSize() == 1, "Duplicate add should not change size");

    root.remove(&child);
    passed &= checkTest(root.getSize() == 0, "Size should return to zero after remove");

    root.remove(&child); // Removing non-existent child should not crash
    passed &= checkTest(root.getSize() == 0, "Removing missing child keeps size zero");

    return passed;
}

bool testPerformCareCascades() {
    std::cout << "Running test: testPerformCareCascades..." << std::endl;
    bool passed = true;

    GreenhouseBed bed("Care Bed");
    MockComponent mockChild;

    bed.add(&mockChild);
    bed.performCare();

    passed &= checkTest(mockChild.cared, "Child component should be cared for");

    return passed;
}

bool testFindPlantInNestedBeds() {
    std::cout << "Running test: testFindPlantInNestedBeds..." << std::endl;
    bool passed = true;

    GreenhouseBed root("Root");
    GreenhouseBed inner("Inner");
    GreenhouseBed leafHolder("Leaf Holder");
    GreenhouseComponent* found = nullptr;

    root.add(&leafHolder);
    root.add(&inner);

    // TODO: Replace with iterator-based traversal when available.
    found = root.findPlantInBed("Inner");
    passed &= checkTest(found == &inner, "findPlantInBed should locate nested bed");

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
