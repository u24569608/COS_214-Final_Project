#include "../include/MatureState.h"
#include "../include/DeadState.h"
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

    if (PlantStateUtils::isResourceStressed(plant) || plant.getHealth() < kMatureHealthFloor) {
        plant.setState(std::make_unique<WitheringState>());
    }
}
} // namespace

std::string MatureState::getName() const {
    return "Mature";
}

void MatureState::onWater(PlantInstance& plant) {
    if (!plant.isReplayingAction()) {
        plant.applyWaterStrategy();
    }
    plant.changeWaterLevel(12);
    plant.changeHealth(1);
    transitionIfNecessary(plant);
}

void MatureState::onFertilize(PlantInstance& plant) {
    if (!plant.isReplayingAction()) {
        plant.applyFertilizeStrategy();
    }
    plant.changeNutrientLevel(12);
    plant.changeHealth(1);
    transitionIfNecessary(plant);
}

void MatureState::onTick(PlantInstance& plant) {
    if (PlantStateUtils::isResourceStressed(plant)) {
        plant.changeHealth(-6);
    } else {
        plant.changeHealth(-1);
    }
    transitionIfNecessary(plant);
}
