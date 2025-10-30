#include "../include/PlantInstance.h"
#include "../include/FrequentWatering.h"
#include "../include/SparseWatering.h"
#include "../include/SeasonalWatering.h"
#include "../include/LiquidFertilizer.h"
#include "../include/SlowReleaseFertilizer.h"
#include "../include/OrganicFertilizer.h"
#include "../include/Plant.h"

/**
 * @file strategy_test.cpp
 * @brief Checks watering and fertilizing strategy selections using manual validation.
 */
#include <iostream>
#include <cassert>

using namespace std;

// -------------------- Flower Class --------------------
class Flower : public Plant {
public:
    // Constructor
    Flower(const std::string& nameValue, const std::string& typeValue) {
        setName(nameValue);
        setType(typeValue);
    }

    // Copy constructor
    Flower(const Flower& other) : Plant(other) { }

    // Implement clone
    Plant* clone() const override {
        return new Flower(*this);
    }
};

// -------------------- Helper Function --------------------
void printStatus(const PlantInstance& plant, const string& context) {
    cout << "---- " << context << " ----" << endl;
    cout << "Health: " << plant.getHealth()
         << ", WaterLevel: " << plant.getWaterLevel()
         << ", NutrientLevel: " << plant.getNutrientLevel() << endl;
}

// -------------------- Main Test --------------------
int main() {
    cout << "=== Strategy Pattern Unit Test ===" << endl;

    // Step 1: Create a concrete plant (Flower) and instance
    Flower* rose = new Flower("Rose", "Flower");
    PlantInstance roseInstance(rose, "Rose_1");

    auto assertRange = [](int value, const char* message) {
        assert((value >= 0 && value <= 100) && message);
    };

    auto assertNonDecreasing = [](int before, int after, const char* message) {
        assert((after >= before) && message);
    };

    // Initial State
    printStatus(roseInstance, "Initial State");

    // ---------------- Watering Strategies ----------------
    FrequentWatering frequent;
    SparseWatering sparse;
    SeasonalWatering seasonal;

    roseInstance.setWaterStrategy(&frequent);
    int waterBefore = roseInstance.getWaterLevel();
    int healthBefore = roseInstance.getHealth();
    roseInstance.performWater();
    int waterAfter = roseInstance.getWaterLevel();
    int healthAfter = roseInstance.getHealth();
    assertNonDecreasing(waterBefore, waterAfter, "FrequentWatering should not reduce water level");
    assertNonDecreasing(healthBefore, healthAfter, "FrequentWatering should not reduce health");
    assertRange(waterAfter, "FrequentWatering should clamp water level within [0,100]");
    assertRange(healthAfter, "FrequentWatering should clamp health within [0,100]");
    printStatus(roseInstance, "After FrequentWatering");

    roseInstance.setWaterStrategy(&sparse);
    waterBefore = roseInstance.getWaterLevel();
    healthBefore = roseInstance.getHealth();
    roseInstance.performWater();
    waterAfter = roseInstance.getWaterLevel();
    healthAfter = roseInstance.getHealth();
    assertNonDecreasing(waterBefore, waterAfter, "SparseWatering should not reduce water level");
    assertNonDecreasing(healthBefore, healthAfter, "SparseWatering should not reduce health");
    assertRange(waterAfter, "SparseWatering should clamp water level within [0,100]");
    assertRange(healthAfter, "SparseWatering should clamp health within [0,100]");
    printStatus(roseInstance, "After SparseWatering");

    roseInstance.setWaterStrategy(&seasonal);
    waterBefore = roseInstance.getWaterLevel();
    healthBefore = roseInstance.getHealth();
    roseInstance.performWater();
    waterAfter = roseInstance.getWaterLevel();
    healthAfter = roseInstance.getHealth();
    assertNonDecreasing(waterBefore, waterAfter, "SeasonalWatering should not reduce water level");
    assertNonDecreasing(healthBefore, healthAfter, "SeasonalWatering should not reduce health");
    assertRange(waterAfter, "SeasonalWatering should clamp water level within [0,100]");
    assertRange(healthAfter, "SeasonalWatering should clamp health within [0,100]");
    printStatus(roseInstance, "After SeasonalWatering");

    // ---------------- Fertilizer Strategies ----------------
    LiquidFertilizer liquid;
    SlowReleaseFertilizer slow;
    OrganicFertilizer organic;

    roseInstance.setFertilizeStrategy(&liquid);
    int nutrientsBefore = roseInstance.getNutrientLevel();
    healthBefore = roseInstance.getHealth();
    roseInstance.performFertilize();
    int nutrientsAfter = roseInstance.getNutrientLevel();
    healthAfter = roseInstance.getHealth();
    assertNonDecreasing(nutrientsBefore, nutrientsAfter, "LiquidFertilizer should not reduce nutrient level");
    assertNonDecreasing(healthBefore, healthAfter, "LiquidFertilizer should not reduce health");
    assertRange(nutrientsAfter, "LiquidFertilizer should clamp nutrients within [0,100]");
    assertRange(healthAfter, "LiquidFertilizer should clamp health within [0,100]");
    printStatus(roseInstance, "After LiquidFertilizer");

    roseInstance.setFertilizeStrategy(&slow);
    nutrientsBefore = roseInstance.getNutrientLevel();
    healthBefore = roseInstance.getHealth();
    roseInstance.performFertilize();
    nutrientsAfter = roseInstance.getNutrientLevel();
    healthAfter = roseInstance.getHealth();
    assertNonDecreasing(nutrientsBefore, nutrientsAfter, "SlowReleaseFertilizer should not reduce nutrient level");
    assertNonDecreasing(healthBefore, healthAfter, "SlowReleaseFertilizer should not reduce health");
    assertRange(nutrientsAfter, "SlowReleaseFertilizer should clamp nutrients within [0,100]");
    assertRange(healthAfter, "SlowReleaseFertilizer should clamp health within [0,100]");
    printStatus(roseInstance, "After SlowReleaseFertilizer");

    roseInstance.setFertilizeStrategy(&organic);
    nutrientsBefore = roseInstance.getNutrientLevel();
    healthBefore = roseInstance.getHealth();
    roseInstance.performFertilize();
    nutrientsAfter = roseInstance.getNutrientLevel();
    healthAfter = roseInstance.getHealth();
    assertNonDecreasing(nutrientsBefore, nutrientsAfter, "OrganicFertilizer should not reduce nutrient level");
    assertNonDecreasing(healthBefore, healthAfter, "OrganicFertilizer should not reduce health");
    assertRange(nutrientsAfter, "OrganicFertilizer should clamp nutrients within [0,100]");
    assertRange(healthAfter, "OrganicFertilizer should clamp health within [0,100]");
    printStatus(roseInstance, "After OrganicFertilizer");

    // ---------------- Assertions ----------------
    assertRange(roseInstance.getHealth(), "Plant health should remain within [0,100]");
    assertRange(roseInstance.getWaterLevel(), "Water level should remain within [0,100]");
    assertRange(roseInstance.getNutrientLevel(), "Nutrient level should remain within [0,100]");
    assert(roseInstance.getHealth() > 0 && "Plant health should remain positive.");

    cout << "\n✅ Strategy Pattern tests completed successfully!" << endl;

    delete rose;
    return 0;
}
