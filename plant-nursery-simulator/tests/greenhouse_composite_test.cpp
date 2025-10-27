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
    TrackingPlant orphan(&prototype, "Orphan");

    GreenhouseBed outer("Outer");
    GreenhouseBed inner("Inner");

    inner.add(&orphan);
    outer.add(&inner);

    inner.remove(&orphan);
    outer.performCare();

    ASSERT_EQ_INT(orphan.getCareCount(), 0, "Plant removed from bed should not receive care");
}

void testNestedBedsCascadeCare() {
    std::cout << "Running test: testNestedBedsCascadeCare..." << std::endl;

    DummyPlant prototype;
    TrackingPlant plantA(&prototype, "PlantA");
    TrackingPlant plantB(&prototype, "PlantB");

    GreenhouseBed root("Root");
    GreenhouseBed child("Child");

    child.add(&plantA);
    root.add(&child);
    root.add(&plantB);

    root.performCare();

    ASSERT_EQ_INT(plantA.getCareCount(), 1, "Nested plant should receive cascaded care");
    ASSERT_EQ_INT(plantB.getCareCount(), 1, "Direct child plant should receive care exactly once");
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
