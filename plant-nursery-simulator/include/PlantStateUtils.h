#ifndef PLANT_STATE_UTILS_H
#define PLANT_STATE_UTILS_H

#include "PlantStateThresholds.h"
#include "PlantInstance.h"

/**
 * @file PlantStateUtils.h
 * @brief Common helper functions shared by lifecycle state implementations.
 */
namespace PlantStateUtils {

/**
 * @brief Determines whether the plant's health has fallen to the death threshold.
 * @param plant Context plant instance to inspect.
 * @return True if health is at or below the critical death boundary.
 */
inline bool isDead(const PlantInstance& plant) {
    return plant.getHealth() <= PlantStateThresholds::kDeadHealthThreshold;
}

/**
 * @brief Checks if water, nutrient, and health levels justify transitioning from seed to growing.
 * @param plant Context plant instance to inspect.
 * @return True when all seed-to-growing thresholds are met or exceeded.
 */
inline bool meetsSeedToGrowingRequirements(const PlantInstance& plant) {
    return plant.getWaterLevel() >= PlantStateThresholds::kSeedToGrowingWater &&
           plant.getNutrientLevel() >= PlantStateThresholds::kSeedToGrowingNutrients &&
           plant.getHealth() >= PlantStateThresholds::kSeedToGrowingHealth;
}

/**
 * @brief Checks if the plant satisfies the criteria to progress to the mature state.
 * @param plant Context plant instance to inspect.
 * @return True when health, water, and nutrient levels clear the mature thresholds.
 */
inline bool meetsGrowingToMatureRequirements(const PlantInstance& plant) {
    return plant.getHealth() >= PlantStateThresholds::kGrowingToMatureHealth &&
           plant.getWaterLevel() >= PlantStateThresholds::kGrowingToMatureWater &&
           plant.getNutrientLevel() >= PlantStateThresholds::kGrowingToMatureNutrients;
}

/**
 * @brief Reports whether the plant is currently suffering from low resources.
 * @param plant Context plant instance to inspect.
 * @return True when either water or nutrients are below their withering thresholds.
 */
inline bool isResourceStressed(const PlantInstance& plant) {
    return plant.getWaterLevel() < PlantStateThresholds::kWitheringWaterThreshold ||
           plant.getNutrientLevel() < PlantStateThresholds::kWitheringNutrientThreshold;
}

/**
 * @brief Indicates whether resource levels have recovered sufficiently to leave the withering state.
 * @param plant Context plant instance to inspect.
 * @return True when both water and nutrient levels exceed the seed-to-growing thresholds.
 */
inline bool hasRecoveredResources(const PlantInstance& plant) {
    return plant.getWaterLevel() >= PlantStateThresholds::kSeedToGrowingWater &&
           plant.getNutrientLevel() >= PlantStateThresholds::kSeedToGrowingNutrients;
}

} // namespace PlantStateUtils

#endif // PLANT_STATE_UTILS_H
