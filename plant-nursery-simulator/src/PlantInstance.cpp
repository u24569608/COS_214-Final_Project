/**
 * @file PlantInstance.cpp
 * @brief Combined implementation of the PlantInstance class.
 */
#include "PlantInstance.h"
#include "Plant.h"
#include "WaterStrategy.h"
#include "FertilizeStrategy.h"
#include "SeedState.h" // Assuming SeedState is the default
#include <iostream>    // Included from the second file

/**
 * @brief Constructor
 * @param proto A *cloned* plant prototype.
 */
PlantInstance::PlantInstance(Plant* proto) : plantType(proto) {
    // Set initial state
    this->plantState = new SeedState(); 
    
    // Use the prototype to set the *initial* strategies
    // These pointers are *owned* by the prototype.
    this->wStrategy = plantType->getDefaultWaterStrat();
    this->fStrategy = plantType->getDefaultFertStrat();

    // Set initial levels
    this->health = 100;
    this->waterLevel = 100;
    this->nutrientLevel = 100;
}

/**
 * @brief Destructor
 */
PlantInstance::~PlantInstance() {
    // The instance owns its cloned prototype and must delete it
    delete plantType;
    // The instance owns its state object
    delete plantState;
    
    // The instance does NOT own the strategy pointers (wStrategy, fStrategy).
    // They are owned by the prototype and will be deleted when 'delete plantType'
    // calls the Plant base class destructor.
}

// === Strategy Pattern ===
void PlantInstance::setWaterStrategy(WaterStrategy* ws) {
    this->wStrategy = ws;
}

WaterStrategy* PlantInstance::getWaterStrategy() const {
    return wStrategy;
}

void PlantInstance::setFertilizeStrategy(FertilizeStrategy* fs) {
    this->fStrategy = fs;
}

FertilizeStrategy* PlantInstance::getFertilizeStrategy() const {
    return fStrategy;
}

// === Command Pattern (Receiver methods) ===
void PlantInstance::performWater() {
    if (wStrategy) {
        wStrategy->water(this); // Pass 'this' as the Context
    }
}

void PlantInstance::performFertilize() {
    if (fStrategy) {
        fStrategy->fertilize(this); // Pass 'this' as the Context
    }
}

// === Observer / State methods ===
void PlantInstance::applyGrowthTick() { 
    /* ... Stub ... */ 
    // This is where you would update health, water, nutrients
    // and potentially change the plantState.
}

bool PlantInstance::isThirsty() const { 
    return waterLevel < 50; 
}

bool PlantInstance::needsFertilizing() const { 
    return nutrientLevel < 50; 
}

// === Composite Pattern (Leaf method) ---
//void PlantInstance::performCare() {
    // Stub from second file
//}

// === Getters / Setters ===
std::string PlantInstance::getPlantTypeName() const {
    // Get name from the prototype
    return plantType ? plantType->getName() : "Unknown";
}

int PlantInstance::getHealth() const { 
    return health; 
}

void PlantInstance::setHealth(int newHealth) { 
    health = newHealth; 
}

int PlantInstance::getWaterLevel() const { 
    return waterLevel; 
}
