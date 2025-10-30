/**
 * @file greenhouse_iterator_test.cpp
 * @brief Checks greenhouse iterators for correct traversal semantics.
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../include/GreenhouseBed.h"
#include "../include/GreenhouseIterator.h"
#include "../include/PlantInstance.h"

namespace {

class TestPlant final : public PlantInstance {
public:
    explicit TestPlant(const std::string& label)
        : PlantInstance(nullptr, label) {}
};

bool reportFailure(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "[FAIL] " << message << std::endl;
        return false;
    }
    return true;
}

} // namespace

bool testEmptyBedIterator() {
    std::cout << "Running test: testEmptyBedIterator..." << std::endl;
    bool passed = true;

    GreenhouseBed emptyBed;
    std::unique_ptr<GreenhouseIterator> iterator = emptyBed.createIterator();

    passed &= reportFailure(static_cast<bool>(iterator), "Iterator instance should not be null");
    passed &= reportFailure(iterator->first() == nullptr, "First on empty bed should be nullptr");
    passed &= reportFailure(iterator->currentItem() == nullptr, "Current item should remain nullptr");
    passed &= reportFailure(iterator->hasNext() == false, "hasNext should report false for empty traversal");
    passed &= reportFailure(iterator->next() == nullptr, "Next on empty bed should return nullptr");

    return passed;
}

bool testFlatBedIterationOrder() {
    std::cout << "Running test: testFlatBedIterationOrder..." << std::endl;
    bool passed = true;

    GreenhouseBed bed("Row A");
    auto plantOne = std::make_unique<TestPlant>("Plant One");
    auto plantTwo = std::make_unique<TestPlant>("Plant Two");
    auto plantThree = std::make_unique<TestPlant>("Plant Three");

    TestPlant* rawOne = plantOne.get();
    TestPlant* rawTwo = plantTwo.get();
    TestPlant* rawThree = plantThree.get();

    bed.add(std::move(plantOne));
    bed.add(std::move(plantTwo));
    bed.add(std::move(plantThree));

    std::unique_ptr<GreenhouseIterator> iterator = bed.createIterator();
    passed &= reportFailure(static_cast<bool>(iterator), "Iterator should not be null");

    PlantInstance* first = iterator->first();
    passed &= reportFailure(first == rawOne, "First plant should be Plant One");

    passed &= reportFailure(iterator->hasNext(), "Iterator should report more elements after first");
    passed &= reportFailure(iterator->currentItem() == rawOne, "Current item should stay on Plant One after first()");

    PlantInstance* second = iterator->next();
    passed &= reportFailure(second == rawTwo, "Next plant should be Plant Two");
    PlantInstance* third = iterator->next();
    passed &= reportFailure(third == rawThree, "Next plant should be Plant Three");
    passed &= reportFailure(iterator->next() == nullptr, "Advancing past end should yield nullptr");
    passed &= reportFailure(iterator->hasNext() == false, "Iterator should report exhaustion after end");

    return passed;
}

bool testNestedBedDepthFirstOrder() {
    std::cout << "Running test: testNestedBedDepthFirstOrder..." << std::endl;
    bool passed = true;

    GreenhouseBed root("Root");
    auto leftBed = std::make_unique<GreenhouseBed>("Left");
    auto rightBed = std::make_unique<GreenhouseBed>("Right");

    auto plantLeft = std::make_unique<TestPlant>("Left Plant");
    auto plantMiddle = std::make_unique<TestPlant>("Middle Plant");
    auto plantRight = std::make_unique<TestPlant>("Right Plant");

    TestPlant* rawLeft = plantLeft.get();
    TestPlant* rawMiddle = plantMiddle.get();
    TestPlant* rawRight = plantRight.get();

    leftBed->add(std::move(plantLeft));
    rightBed->add(std::move(plantRight));

    root.add(std::move(leftBed));
    root.add(std::move(plantMiddle));
    root.add(std::move(rightBed));

    std::unique_ptr<GreenhouseIterator> iterator = root.createIterator();
    passed &= reportFailure(static_cast<bool>(iterator), "Iterator should not be null for nested structure");

    std::vector<PlantInstance*> expectedOrder = {rawLeft, rawMiddle, rawRight};
    std::vector<PlantInstance*> observedOrder;

    for (PlantInstance* plant = iterator->first(); plant != nullptr; plant = iterator->next()) {
        observedOrder.push_back(plant);
    }

    passed &= reportFailure(observedOrder.size() == expectedOrder.size(),
        "Iterator should visit every plant in nested structure");

    for (std::size_t i = 0; i < std::min(observedOrder.size(), expectedOrder.size()); ++i) {
        const std::string message =
            "Iterator order mismatch at index " + std::to_string(i);
        passed &= reportFailure(observedOrder[i] == expectedOrder[i], message);
    }

    return passed;
}

bool testIteratorRefreshesOnFirst() {
    std::cout << "Running test: testIteratorRefreshesOnFirst..." << std::endl;
    bool passed = true;

    GreenhouseBed bed("Dynamic Bed");
    auto initial = std::make_unique<TestPlant>("Initial Plant");
    auto lateArrival = std::make_unique<TestPlant>("Late Arrival");

    TestPlant* rawInitial = initial.get();
    TestPlant* rawLate = lateArrival.get();

    bed.add(std::move(initial));

    std::unique_ptr<GreenhouseIterator> iterator = bed.createIterator();
    passed &= reportFailure(static_cast<bool>(iterator), "Iterator should not be null");

    std::vector<PlantInstance*> initialOrder;
    for (PlantInstance* plant = iterator->first(); plant != nullptr; plant = iterator->next()) {
        initialOrder.push_back(plant);
    }

    passed &= reportFailure(initialOrder.size() == 1, "Iterator should recognise the single existing plant");
    passed &= reportFailure(initialOrder.front() == rawInitial, "Initial traversal should contain the first plant");

    bed.add(std::move(lateArrival));

    bool foundLateArrival = false;
    for (PlantInstance* plant = iterator->first(); plant != nullptr; plant = iterator->next()) {
        if (plant == rawLate) {
            foundLateArrival = true;
            break;
        }
    }

    passed &= reportFailure(foundLateArrival, "Iterator::first should rebuild traversal after structure changes");

    return passed;
}

int main() {
    int passed = 0;
    int total = 0;

    if (testEmptyBedIterator()) {
        ++passed;
    }
    ++total;

    if (testFlatBedIterationOrder()) {
        ++passed;
    }
    ++total;

    if (testNestedBedDepthFirstOrder()) {
        ++passed;
    }
    ++total;

    if (testIteratorRefreshesOnFirst()) {
        ++passed;
    }
    ++total;

    std::cout << "\n---------------------------\n";
    std::cout << "     TEST SUMMARY          \n";
    std::cout << " Tests Passed: " << passed << " / " << total << std::endl;
    std::cout << "---------------------------\n";

    return (passed == total) ? 0 : 1;
}
