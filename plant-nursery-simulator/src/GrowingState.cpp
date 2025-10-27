#include "../include/GrowingState.h"
#include "../include/DeadState.h"
#include "../include/MatureState.h"
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

    if (isResourceStressed(plant)) {
        plant.setState(std::make_unique<WitheringState>());
        return;
    }

    if (plant.getHealth() >= kGrowingToMatureHealth &&
        plant.getWaterLevel() >= kGrowingToMatureWater &&
        plant.getNutrientLevel() >= kGrowingToMatureNutrients) {
        plant.setState(std::make_unique<MatureState>());
    }
}
} // namespace

std::string GrowingState::getName() const {
    return "Growing";
}

void GrowingState::onWater(PlantInstance& plant) {
    plant.applyWaterStrategy();
    plant.changeWaterLevel(18);
    plant.changeHealth(3);
    transitionIfNecessary(plant);
}

void GrowingState::onFertilize(PlantInstance& plant) {
    plant.applyFertilizeStrategy();
    plant.changeNutrientLevel(18);
    plant.changeHealth(3);
    transitionIfNecessary(plant);
}

void GrowingState::onTick(PlantInstance& plant) {
    if (isResourceStressed(plant)) {
        plant.changeHealth(-7);
    } else {
        plant.changeHealth(2);
    }
    transitionIfNecessary(plant);
}
