#include "../include/Plant.h"

Plant::~Plant() = default;

Plant* Plant::clone() const {
    // TODO(FR3): Provide deep copy logic when prototype catalogue is implemented.
    return nullptr;
}

std::string Plant::getName() const {
    return name;
}

std::string Plant::getType() const {
    return type;
}

WaterStrategy* Plant::getDefaultWaterStrat() const {
    return defaultWaterStrat;
}

FertilizeStrategy* Plant::getDefaultFertStrat() const {
    return defaultFertilizerStrat;
}

