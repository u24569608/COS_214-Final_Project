#include "../include/Plant.h"

Plant::Plant() : defaultWaterStrat(nullptr), defaultFertilizerStrat(nullptr) {}

Plant::~Plant() = default;

std::string Plant::getName() const {
    return name;
}

std::string Plant::getType() const {
    return type;
}

void Plant::setName(const std::string& newName) {
    name = newName;
}

void Plant::setType(const std::string& newType) {
    type = newType;
}

WaterStrategy* Plant::getDefaultWaterStrat() const {
    return defaultWaterStrat;
}

FertilizeStrategy* Plant::getDefaultFertStrat() const {
    return defaultFertilizerStrat;
}

void Plant::setDefaultWaterStrat(WaterStrategy* strategy) {
    defaultWaterStrat = strategy;
}

void Plant::setDefaultFertStrat(FertilizeStrategy* strategy) {
    defaultFertilizerStrat = strategy;
}
