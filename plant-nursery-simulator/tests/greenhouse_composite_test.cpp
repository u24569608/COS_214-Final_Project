#include <iostream>
#include <memory>

#include "../include/GreenhouseBed.h"
#include "../include/PlantInstance.h"
#include "../include/Plant.h"

namespace {

class DummyPlant : public Plant {
public:
    DummyPlant() {
        setName("Dummy");
    }

    Plant* clone() const override {
        return new DummyPlant(*this);
    }
};

class TrackingPlant : public PlantInstance {
public:
    TrackingPlant(Plant* prototype, std::string label)
        : PlantInstance(prototype, std::move(label)), careCount(0) {}

    void performCare() override {
        ++careCount;
        PlantInstance::performCare();
    }

    int getCareCount() const { return careCount; }

private:
    int careCount;
};

int failures = 0;

void ASSERT_TRUE(bool expr, const std::string& msg) {
    if (!expr) {
        std::cerr << "[ASSERT_TRUE FAILED] " << msg << std::endl;
        ++failures;
    }
}

void ASSERT_EQ_INT(int actual, int expected, const std::string& msg) {
    if (actual != expected) {
        std::cerr << "[ASSERT_EQ_INT FAILED] " << msg
                  << " (expected " << expected << ", got " << actual << ")" << std::endl;
        ++failures;
    }
}

} // namespace

void testAddOrphanedPlantDoesNotDuplicateCare() {
    std::cout << "Running test: testAddOrphanedPlantDoesNotDuplicateCare..." << std::endl;

    DummyPlant prototype;
    GreenhouseBed outer("Outer");
    auto inner = std::make_unique<GreenhouseBed>("Inner");
    GreenhouseBed* innerPtr = inner.get();

    auto orphan = std::make_unique<TrackingPlant>(&prototype, "Orphan");
    TrackingPlant* orphanPtr = orphan.get();

    innerPtr->add(std::move(orphan));
    outer.add(std::move(inner));

    std::unique_ptr<PlantInstance> released = innerPtr->releasePlant(orphanPtr);
    ASSERT_TRUE(static_cast<bool>(released), "Released plant should remain accessible to caller");
    std::unique_ptr<TrackingPlant> reclaimed(static_cast<TrackingPlant*>(released.release()));

    outer.performCare();

    ASSERT_EQ_INT(reclaimed->getCareCount(), 0, "Plant removed from bed should not receive care");
}

void testNestedBedsCascadeCare() {
    std::cout << "Running test: testNestedBedsCascadeCare..." << std::endl;

    DummyPlant prototype;
    GreenhouseBed root("Root");
    auto child = std::make_unique<GreenhouseBed>("Child");
    GreenhouseBed* childPtr = child.get();

    auto plantA = std::make_unique<TrackingPlant>(&prototype, "PlantA");
    auto plantB = std::make_unique<TrackingPlant>(&prototype, "PlantB");

    TrackingPlant* rawA = plantA.get();
    TrackingPlant* rawB = plantB.get();

    childPtr->add(std::move(plantA));
    root.add(std::move(child));
    root.add(std::move(plantB));

    root.performCare();

    ASSERT_EQ_INT(rawA->getCareCount(), 1, "Nested plant should receive cascaded care");
    ASSERT_EQ_INT(rawB->getCareCount(), 1, "Direct child plant should receive care exactly once");
}

int main() {
    std::cout << "== Greenhouse Composite UNIT TESTS ==" << std::endl;

    testAddOrphanedPlantDoesNotDuplicateCare();
    testNestedBedsCascadeCare();

    if (failures == 0) {
        std::cout << "\n[PASS] All greenhouse composite unit tests passed." << std::endl;
        return 0;
    }

    std::cerr << "\n[FAIL] " << failures << " test(s) failed." << std::endl;
    return 1;
}
