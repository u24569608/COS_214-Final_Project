#include "../include/GrowingState.h"
#include "../include/DeadState.h"
#include "../include/MatureState.h"
#include "../include/PlantInstance.h"
#include "../include/PlantStateThresholds.h"
#include "../include/PlantStateUtils.h"
#include "../include/WitheringState.h"
#include <memory>

namespace {
using namespace PlantStateThresholds;

void transitionIfNecessary(PlantInstance& plant) {
    if (PlantStateUtils::isDead(plant)) {
        plant.setState(std::make_unique<DeadState>());
        return;
    }

    if (PlantStateUtils::isResourceStressed(plant)) {
        plant.setState(std::make_unique<WitheringState>());
        return;
    }

    if (PlantStateUtils::meetsGrowingToMatureRequirements(plant)) {
        plant.setState(std::make_unique<MatureState>());
    }
}
} // namespace

std::string GrowingState::getName() const {
    return "Growing";
}

void GrowingState::onWater(PlantInstance& plant) {
    if (!plant.isReplayingAction()) {
        plant.applyWaterStrategy();
    }
    plant.changeWaterLevel(18);
    plant.changeHealth(3);
    transitionIfNecessary(plant);
}

void GrowingState::onFertilize(PlantInstance& plant) {
    if (!plant.isReplayingAction()) {
        plant.applyFertilizeStrategy();
    }
    plant.changeNutrientLevel(18);
    plant.changeHealth(3);
    transitionIfNecessary(plant);
}

void GrowingState::onTick(PlantInstance& plant) {
    if (PlantStateUtils::isResourceStressed(plant)) {
        plant.changeHealth(-7);
    } else {
        plant.changeHealth(2);
    }
    transitionIfNecessary(plant);
}
