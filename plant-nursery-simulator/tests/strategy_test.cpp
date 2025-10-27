#include "../include/PlantInstance.h"
#include "../include/FrequentWatering.h"
#include "../include/SparseWatering.h"
#include "../include/SeasonalWatering.h"
#include "../include/LiquidFertilizer.h"
#include "../include/SlowReleaseFertilizer.h"
#include "../include/OrganicFertilizer.h"
#include "../include/Plant.h"

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

    // Initial State
    printStatus(roseInstance, "Initial State");

    // ---------------- Watering Strategies ----------------
    FrequentWatering frequent;
    SparseWatering sparse;
    SeasonalWatering seasonal;

    roseInstance.setWaterStrategy(&frequent);
    roseInstance.performWater();
    printStatus(roseInstance, "After FrequentWatering");

    roseInstance.setWaterStrategy(&sparse);
    roseInstance.performWater();
    printStatus(roseInstance, "After SparseWatering");

    roseInstance.setWaterStrategy(&seasonal);
    roseInstance.performWater();
    printStatus(roseInstance, "After SeasonalWatering");

    // ---------------- Fertilizer Strategies ----------------
    LiquidFertilizer liquid;
    SlowReleaseFertilizer slow;
    OrganicFertilizer organic;

    roseInstance.setFertilizeStrategy(&liquid);
    roseInstance.performFertilize();
    printStatus(roseInstance, "After LiquidFertilizer");

    roseInstance.setFertilizeStrategy(&slow);
    roseInstance.performFertilize();
    printStatus(roseInstance, "After SlowReleaseFertilizer");

    roseInstance.setFertilizeStrategy(&organic);
    roseInstance.performFertilize();
    printStatus(roseInstance, "After OrganicFertilizer");

    // ---------------- Assertions ----------------
    assert(roseInstance.getHealth() > 0 && "Plant health should remain positive.");
    assert(roseInstance.getWaterLevel() >= 0 && "Water level should not be negative.");
    assert(roseInstance.getNutrientLevel() >= 0 && "Nutrient level should not be negative.");

    cout << "\n✅ Strategy Pattern tests completed successfully!" << endl;

    delete rose;
    return 0;
}
