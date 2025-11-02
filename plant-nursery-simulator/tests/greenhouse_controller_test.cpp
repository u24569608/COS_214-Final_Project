/**
 * @file greenhouse_controller_test.cpp
 * @brief Verifies greenhouse controller coordination logic via manual assertions.
 */
#include <iostream>
#include <memory>
#include <vector>

#include "../include/GreenhouseController.h"
#include "../include/GreenhouseBed.h"
#include "../include/PlantInstance.h"
#include "../include/Plant.h"

static int failures = 0;

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

class DummyPlant : public Plant {
public:
    explicit DummyPlant(const std::string& name) {
        setName(name);
    }

    Plant* clone() const override {
        return new DummyPlant(*this);
    }
};

void testRunGrowthTickAdvancesAllPlants() {
    std::cout << "Running test: testRunGrowthTickAdvancesAllPlants..." << std::endl;

    DummyPlant prototype("TestPlant");
    GreenhouseBed bed("Controller Bed");
    std::vector<PlantInstance*> trackedPlants;

    auto plantAlpha = std::make_unique<PlantInstance>(&prototype, "PlantAlpha");
    auto plantBeta = std::make_unique<PlantInstance>(&prototype, "PlantBeta");

    plantAlpha->setWaterLevel(100);
    plantAlpha->setNutrientLevel(100);
    plantBeta->setWaterLevel(100);
    plantBeta->setNutrientLevel(100);

    trackedPlants.push_back(plantAlpha.get());
    trackedPlants.push_back(plantBeta.get());

    bed.add(std::move(plantAlpha));
    bed.add(std::move(plantBeta));

    GreenhouseController controller(&bed);
    controller.runGrowthTick();

    for (PlantInstance* plant : trackedPlants) {
        ASSERT_EQ_INT(plant->getWaterLevel(), 95, "Growth tick should reduce water by 5");
        ASSERT_EQ_INT(plant->getNutrientLevel(), 97, "Growth tick should reduce nutrients by 3");
    }
}

void testNullRootSafelyNoops() {
    std::cout << "Running test: testNullRootSafelyNoops..." << std::endl;
    GreenhouseController controller;
    controller.runGrowthTick();
    ASSERT_TRUE(true, "Calling runGrowthTick with null root should not crash");
}

int main() {
    std::cout << "== Greenhouse Controller UNIT TESTS ==" << std::endl;

    testRunGrowthTickAdvancesAllPlants();
    testNullRootSafelyNoops();

    if (failures == 0) {
        std::cout << "\n[PASS] All greenhouse controller unit tests passed." << std::endl;
        return 0;
    }

    std::cerr << "\n[FAIL] " << failures << " test(s) failed." << std::endl;
    return 1;
}
