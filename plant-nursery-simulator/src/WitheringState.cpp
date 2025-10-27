#include "../include/WitheringState.h"
#include "../include/DeadState.h"
#include "../include/GrowingState.h"
#include "../include/MatureState.h"
#include "../include/PlantInstance.h"
#include "../include/PlantStateThresholds.h"
#include <memory>

namespace {
using namespace PlantStateThresholds;

bool hasRecoveredResources(const PlantInstance& plant) {
    return plant.getWaterLevel() >= kSeedToGrowingWater &&
           plant.getNutrientLevel() >= kSeedToGrowingNutrients;
}

void transitionIfNecessary(PlantInstance& plant) {
    if (plant.getHealth() <= kDeadHealthThreshold ||
        plant.getHealth() <= kWitheringCriticalHealth) {
        plant.setState(std::make_unique<DeadState>());
        return;
    }

    if (!hasRecoveredResources(plant)) {
        return;
    }

    if (plant.getHealth() >= kGrowingToMatureHealth &&
        plant.getWaterLevel() >= kGrowingToMatureWater &&
        plant.getNutrientLevel() >= kGrowingToMatureNutrients) {
        plant.setState(std::make_unique<MatureState>());
    } else if (plant.getHealth() >= kSeedToGrowingHealth &&
               plant.getHealth() >= kWitheringRecoveryHealth) {
        plant.setState(std::make_unique<GrowingState>());
    }
}
} // namespace

std::string WitheringState::getName() const {
    return "Withering";
}

void WitheringState::onWater(PlantInstance& plant) {
    plant.applyWaterStrategy();
    plant.changeWaterLevel(22);
    plant.changeHealth(5);
    transitionIfNecessary(plant);
}

void WitheringState::onFertilize(PlantInstance& plant) {
    plant.applyFertilizeStrategy();
    plant.changeNutrientLevel(22);
    plant.changeHealth(4);
    transitionIfNecessary(plant);
}

void WitheringState::onTick(PlantInstance& plant) {
    plant.changeHealth(-6);
    transitionIfNecessary(plant);
}
