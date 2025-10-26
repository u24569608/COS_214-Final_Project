#include "../include/PlantInstance.h"
#include "../include/Plant.h" // We need this for the getPlantTypeName()
#include "../include/WaterStrategy.h"
#include "../include/FertilizeStrategy.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>

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
    return waterLevel < 50; 
}

bool PlantInstance::needsFertilizing() const { 
    return nutrientLevel < 50; 
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
    static std::unordered_map<std::string, int> nameCounters;
    if (plantPrototype) {
        const std::string baseName = plantPrototype->getName();
        int& counter = nameCounters[baseName];
        ++counter;
        return baseName + std::to_string(counter);
    }
    const std::string baseName = "Unnamed Plant";
    int& counter = nameCounters[baseName];
    ++counter;
    return baseName + std::to_string(counter);
}
