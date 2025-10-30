/**
 * @file WitheringState.cpp
 * @brief Implements the WitheringState behaviour defined in the corresponding header.
 */

#include "../include/WitheringState.h"
#include "../include/DeadState.h"
#include "../include/GrowingState.h"
#include "../include/MatureState.h"
#include "../include/PlantInstance.h"
#include "../include/PlantStateThresholds.h"
#include "../include/PlantStateUtils.h"
#include <memory>

namespace {
using namespace PlantStateThresholds;

void transitionIfNecessary(PlantInstance& plant) {
    if (PlantStateUtils::isDead(plant) ||
        plant.getHealth() <= kWitheringCriticalHealth) {
        plant.setState(std::make_unique<DeadState>());
        return;
    }

    if (!PlantStateUtils::hasRecoveredResources(plant)) {
        return;
    }

    if (PlantStateUtils::meetsGrowingToMatureRequirements(plant)) {
        plant.setState(std::make_unique<MatureState>());
    } else if (plant.getHealth() >= kWitheringRecoveryHealth) {
        plant.setState(std::make_unique<GrowingState>());
    }
}
} // namespace

std::string WitheringState::getName() const {
    return "Withering";
}

void WitheringState::onWater(PlantInstance& plant) {
    if (!plant.isReplayingAction()) {
        plant.applyWaterStrategy();
    }
    plant.changeWaterLevel(22);
    plant.changeHealth(5);
    transitionIfNecessary(plant);
}

void WitheringState::onFertilize(PlantInstance& plant) {
    if (!plant.isReplayingAction()) {
        plant.applyFertilizeStrategy();
    }
    plant.changeNutrientLevel(22);
    plant.changeHealth(4);
    transitionIfNecessary(plant);
}

void WitheringState::onTick(PlantInstance& plant) {
    plant.changeHealth(-6);
    transitionIfNecessary(plant);
}
