#include "../include/PlantInstance.h"
#include "../include/Plant.h" // We need this for the getPlantTypeName()
#include "../include/WaterStrategy.h"
#include "../include/FertilizeStrategy.h"
#include <algorithm>
#include <iostream>

// --- Constructor & Destructor ---
PlantInstance::PlantInstance(Plant* plantType, std::string instanceName) 
    : GreenhouseComponent(deriveInstanceName(plantType, instanceName)),
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
    constexpr int kDefaultWaterConsumption = 5;
    constexpr int kDefaultNutrientConsumption = 3;
    // TODO(FR12): Allow tuning of consumption rates when balancing rules are available.
    waterLevel = std::max(0, waterLevel - kDefaultWaterConsumption);
    nutrientLevel = std::max(0, nutrientLevel - kDefaultNutrientConsumption);

    if (plantState) {
        plantState->onTick(*this);
    }
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

int PlantInstance::getNutrientLevel() const {
    return this->nutrientLevel;
}

std::string PlantInstance::getPlantTypeName() const {
    return plantType ? plantType->getName() : "Unknown Plant";
}

void PlantInstance::rename(const std::string& newName) {
    if (newName.empty()) {
        return;
    }
    name = newName;
}

std::string PlantInstance::deriveInstanceName(Plant* plantPrototype, const std::string& instanceName) {
    if (!instanceName.empty()) {
        return instanceName;
    }
    if (plantPrototype) {
        return plantPrototype->getName();
    }
    return "Unnamed Plant";
}
