#include "../include/PlantInstance.h"
#include "../include/Plant.h" // We need this for the getPlantTypeName()
#include "../include/WaterStrategy.h"
#include "../include/FertilizeStrategy.h"
#include <iostream>

// --- Constructor & Destructor ---
PlantInstance::PlantInstance(Plant* plantType) 
    : GreenhouseComponent(plantType ? "Prototype Plant" : "Unnamed Plant"),
      plantType(plantType), 
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
    if (wStrategy) {
        wStrategy->water(*this);
    }
}

void PlantInstance::performFertilize() {
    if (fStrategy) {
        fStrategy->fertilize(*this);
    }
}

// --- Observer Pattern (Subject methods) ---
void PlantInstance::applyGrowthTick() {
    // TODO(FR12): Implement growth tick and notify observers once the observer subsystem is available.
}

bool PlantInstance::isThirsty() const {
    return waterLevel < 50; // Stub logic
}

bool PlantInstance::needsFertilizing() const {
    return nutrientLevel < 50; // Stub logic
}

// --- Composite Pattern (Leaf method) ---
void PlantInstance::performCare() {
    if (isThirsty()) {
        performWater();
    }
    if (needsFertilizing()) {
        performFertilize();
    }
}

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
    // TODO(FR12): Replace stub once Plant exposes a concrete getName().
    return plantType ? "Stub Plant" : "Unknown Plant";
}
