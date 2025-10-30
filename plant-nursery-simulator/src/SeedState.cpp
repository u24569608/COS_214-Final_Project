/**
 * @file SeedState.cpp
 * @brief Implements the SeedState behaviour defined in the corresponding header.
 */

#include "../include/SeedState.h"
#include "../include/DeadState.h"
#include "../include/GrowingState.h"
#include "../include/PlantInstance.h"
#include "../include/PlantStateThresholds.h"
#include "../include/PlantStateUtils.h"
#include <memory>

namespace {
using namespace PlantStateThresholds;

void transitionIfNecessary(PlantInstance& plant) {
    if (PlantStateUtils::isDead(plant)) {
        plant.setState(std::make_unique<DeadState>());
        return;
    }

    if (PlantStateUtils::meetsSeedToGrowingRequirements(plant)) {
        plant.setState(std::make_unique<GrowingState>());
    }
}

void penaliseForLowResources(PlantInstance& plant) {
    const bool belowWater = plant.getWaterLevel() < kSeedToGrowingWater;
    const bool belowNutrients = plant.getNutrientLevel() < kSeedToGrowingNutrients;

    if (belowWater && belowNutrients) {
        plant.changeHealth(-8);
    } else if (belowWater || belowNutrients) {
        plant.changeHealth(-4);
    } else {
        plant.changeHealth(1);
    }
}
} // namespace

std::string SeedState::getName() const {
    return "Seed";
}

void SeedState::onWater(PlantInstance& plant) {
    if (!plant.isReplayingAction()) {
        plant.applyWaterStrategy();
    }
    plant.changeWaterLevel(20);
    plant.changeHealth(4);
    transitionIfNecessary(plant);
}

void SeedState::onFertilize(PlantInstance& plant) {
    if (!plant.isReplayingAction()) {
        plant.applyFertilizeStrategy();
    }
    plant.changeNutrientLevel(18);
    plant.changeHealth(3);
    transitionIfNecessary(plant);
}

void SeedState::onTick(PlantInstance& plant) {
    penaliseForLowResources(plant);
    transitionIfNecessary(plant);
}
