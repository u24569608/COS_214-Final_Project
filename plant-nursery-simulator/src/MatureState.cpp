#include "../include/MatureState.h"
#include "../include/DeadState.h"
#include "../include/PlantInstance.h"
#include "../include/PlantStateThresholds.h"
#include "../include/WitheringState.h"
#include <memory>

namespace {
using namespace PlantStateThresholds;

bool isResourceStressed(const PlantInstance& plant) {
    return plant.getWaterLevel() < kWitheringWaterThreshold ||
           plant.getNutrientLevel() < kWitheringNutrientThreshold;
}

void transitionIfNecessary(PlantInstance& plant) {
    if (plant.getHealth() <= kDeadHealthThreshold) {
        plant.setState(std::make_unique<DeadState>());
        return;
    }

    if (isResourceStressed(plant) || plant.getHealth() < kMatureHealthFloor) {
        plant.setState(std::make_unique<WitheringState>());
    }
}
} // namespace

std::string MatureState::getName() const {
    return "Mature";
}

void MatureState::onWater(PlantInstance& plant) {
    plant.applyWaterStrategy();
    plant.changeWaterLevel(12);
    plant.changeHealth(1);
    transitionIfNecessary(plant);
}

void MatureState::onFertilize(PlantInstance& plant) {
    plant.applyFertilizeStrategy();
    plant.changeNutrientLevel(12);
    plant.changeHealth(1);
    transitionIfNecessary(plant);
}

void MatureState::onTick(PlantInstance& plant) {
    if (isResourceStressed(plant)) {
        plant.changeHealth(-6);
    } else {
        plant.changeHealth(-1);
    }
    transitionIfNecessary(plant);
}
