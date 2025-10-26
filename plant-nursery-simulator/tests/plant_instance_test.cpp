#include <iostream>
#include <string>

#include "../include/Plant.h"
#include "../include/PlantInstance.h"

namespace {

class DummyPlant : public Plant {
public:
    explicit DummyPlant(const std::string& label) {
        name = label;
    }
};

int failures = 0;

void assertTrue(bool expression, const std::string& message) {
    if (!expression) {
        std::cerr << "[ASSERT_TRUE FAILED] " << message << std::endl;
        ++failures;
    }
}

void assertEqStr(const std::string& actual, const std::string& expected, const std::string& message) {
    if (actual == expected) {
        return;
    }
    std::cerr << "[ASSERT_EQ_STR FAILED] " << message
              << " (expected \"" << expected << "\", got \"" << actual << "\")" << std::endl;
    ++failures;
}

} // namespace

void testPrototypeNameMirrorsInstance() {
    std::cout << "Running test: testPrototypeNameMirrorsInstance..." << std::endl;

    DummyPlant prototype("Prototype Rose");
    PlantInstance instance(&prototype);

    assertEqStr(instance.getName(), "Prototype Rose", "PlantInstance should mirror prototype name by default");
    assertEqStr(instance.getPlantTypeName(), "Prototype Rose", "getPlantTypeName should mirror prototype name");
}

void testRenameUpdatesInstanceName() {
    std::cout << "Running test: testRenameUpdatesInstanceName..." << std::endl;

    PlantInstance instance(nullptr, "Initial");
    instance.rename("Renamed Instance");

    assertEqStr(instance.getName(), "Renamed Instance", "rename should update the instance display name");
}

void testGrowthTickLowersResources() {
    std::cout << "Running test: testGrowthTickLowersResources..." << std::endl;

    PlantInstance instance(nullptr, "Resource Test");

    const int startingWater = instance.getWaterLevel();
    const int startingNutrients = instance.getNutrientLevel();

    instance.applyGrowthTick();

    assertTrue(instance.getWaterLevel() < startingWater, "applyGrowthTick should reduce water level");
    assertTrue(instance.getNutrientLevel() < startingNutrients, "applyGrowthTick should reduce nutrient level");

    // Growth tick should not reduce below zero even after multiple ticks.
    for (int i = 0; i < 50; ++i) {
        instance.applyGrowthTick();
    }

    assertTrue(instance.getWaterLevel() >= 0, "Water level should not go below zero");
    assertTrue(instance.getNutrientLevel() >= 0, "Nutrient level should not go below zero");
}

int main() {
    testPrototypeNameMirrorsInstance();
    testRenameUpdatesInstanceName();
    testGrowthTickLowersResources();

    std::cout << "\n---------------------------\n";
    std::cout << "     TEST SUMMARY          \n";
    std::cout << " Tests Passed: " << (3 - failures) << " / 3" << std::endl;
    std::cout << "---------------------------\n";

    if (failures == 0) {
        return 0;
    }
    std::cerr << "[FAIL] " << failures << " test(s) failed." << std::endl;
    return 1;
}
