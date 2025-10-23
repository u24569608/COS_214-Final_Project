#include "../include/PlantInstance.h"
#include "../include/Plant.h" // We need this for the getPlantTypeName()
#include "../include/WaterStrategy.h"
#include "../include/FertilizeStrategy.h"

// --- Constructor & Destructor ---
PlantInstance::PlantInstance(Plant* plantType) 
    : plantType(plantType), 
      wStrategy(nullptr), 
      fStrategy(nullptr), 
      plantState(nullptr), 
      health(100), 
      waterLevel(100), 
      nutrientLevel(100) {
    // Constructor body
}

PlantInstance::~PlantInstance() {
    // Destructor body
    // (We'll worry about deleting pointers later)
}

// --- Strategy Pattern ---
void PlantInstance::setWaterStrategy(WaterStrategy* ws) {
    this->wStrategy = ws;
}

void PlantInstance::setFertilizeStrategy(FertilizeStrategy* fs) {
    this->fStrategy = fs;
}

// --- Command Pattern (Receiver methods) ---
void PlantInstance::performWater() {
    // Stub
}

void PlantInstance::performFertilize() {
    // Stub
}

// --- Observer Pattern (Subject methods) ---
void PlantInstance::applyGrowthTick() {
    // Stub
}

bool PlantInstance::isThirsty() const {
    return waterLevel < 50; // Stub logic
}

bool PlantInstance::needsFertilizing() const {
    return nutrientLevel < 50; // Stub logic
}

// --- Composite Pattern (Leaf method) ---
//void PlantInstance::performCare() {
    // Stub
//}

// --- Getters/Setters ---
int PlantInstance::getHealth() const {
    return this->health;
}

void PlantInstance::setHealth(int newHealth) {
    this->health = newHealth;
}

int PlantInstance::getWaterLevel() const {
    return this->waterLevel;
}

std::string PlantInstance::getPlantTypeName() const {
    // This is a guess. Assumes Plant.h has a getName()
    // If Plant.h doesn't exist, just: return "Stub Plant";
    if (plantType) {
        // return plantType->getName(); // <-- This is probably the real code
        return "Stub Plant"; // <-- This will work for now
    }
    return "Unknown Plant";
}