/**
 * @file Plant.cpp
 * @brief Implementation of the abstract Plant base class.
 */
#include "Plant.h"
#include "WaterStrategy.h"
#include "FertilizeStrategy.h"

// Protected constructor implementation
Plant::Plant(std::string n, std::string t, WaterStrategy* ws, FertilizeStrategy* fs)
    : name(n), type(t), defaultWaterStrat(ws), defaultFertilizerStrat(fs) {
}

// Virtual destructor
Plant::~Plant() {
    // The prototype owns its default strategies.
    // When the prototype is destroyed (by the registry's unique_ptr),
    // it cleans up its strategy objects.
    delete defaultWaterStrat;
    delete defaultFertilizerStrat;
}

// Getter implementations
std::string Plant::getName() const { return name; }
std::string Plant::getType() const { return type; }
WaterStrategy* Plant::getDefaultWaterStrat() const { return defaultWaterStrat; }
FertilizeStrategy* Plant::getDefaultFertStrat() const { return defaultFertilizerStrat; }
