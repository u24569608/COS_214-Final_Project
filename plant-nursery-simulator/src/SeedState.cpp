#include "../include/SeedState.h"
#include "../include/DeadState.h"
#include "../include/GrowingState.h"
#include "../include/PlantInstance.h"
#include "../include/PlantStateThresholds.h"
#include <memory>

namespace {
using namespace PlantStateThresholds;

void transitionIfNecessary(PlantInstance& plant) {
    if (plant.getHealth() <= kDeadHealthThreshold) {
        plant.setState(std::make_unique<DeadState>());
        return;
    }

    if (plant.getWaterLevel() >= kSeedToGrowingWater &&
        plant.getNutrientLevel() >= kSeedToGrowingNutrients &&
        plant.getHealth() >= kSeedToGrowingHealth) {
        plant.setState(std::make_unique<GrowingState>());
    }
}

void penaliseForLowResources(PlantInstance& plant) {
    const bool severelyDry = plant.getWaterLevel() < (kSeedToGrowingWater / 2);
    const bool severelyStarved = plant.getNutrientLevel() < (kSeedToGrowingNutrients / 2);
    if (severelyDry || severelyStarved) {
        plant.changeHealth(-8);
    } else if (plant.getWaterLevel() < kSeedToGrowingWater ||
               plant.getNutrientLevel() < kSeedToGrowingNutrients) {
        plant.changeHealth(-4);
    } else {
        plant.changeHealth(-2);
    }
}
} // namespace

std::string SeedState::getName() const {
    return "Seed";
}

void SeedState::onWater(PlantInstance& plant) {
    plant.applyWaterStrategy();
    plant.changeWaterLevel(20);
    plant.changeHealth(4);
    transitionIfNecessary(plant);
}

void SeedState::onFertilize(PlantInstance& plant) {
    plant.applyFertilizeStrategy();
    plant.changeNutrientLevel(18);
    plant.changeHealth(3);
    transitionIfNecessary(plant);
}

void SeedState::onTick(PlantInstance& plant) {
    penaliseForLowResources(plant);
    transitionIfNecessary(plant);
}
