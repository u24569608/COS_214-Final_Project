#ifndef PLANT_STATE_THRESHOLDS_H
#define PLANT_STATE_THRESHOLDS_H

/**
 * @file PlantStateThresholds.h
 * @brief Centralised constants describing lifecycle transition boundaries.
 */
namespace PlantStateThresholds {
constexpr int kSeedToGrowingWater = 60;        ///< Water needed before a seed can sprout.
constexpr int kSeedToGrowingNutrients = 55;    ///< Nutrients required to support germination.
constexpr int kSeedToGrowingHealth = 70;       ///< Baseline health for leaving the seed state.

constexpr int kGrowingToMatureHealth = 85;     ///< Health level that unlocks the mature state.
constexpr int kGrowingToMatureWater = 70;      ///< Water requirement shared by growing and mature plants.
constexpr int kGrowingToMatureNutrients = 70;  ///< Nutrient requirement shared by growing and mature plants.

constexpr int kMatureHealthFloor = 60;         ///< Falling below this health forces a mature plant to wither.

constexpr int kWitheringWaterThreshold = 35;   ///< Water level that triggers resource stress.
constexpr int kWitheringNutrientThreshold = 30;///< Nutrient level that triggers resource stress.
constexpr int kWitheringRecoveryHealth = 65;   ///< Health needed to recover from withering.
constexpr int kWitheringCriticalHealth = 20;   ///< Health that causes an immediate death transition.

constexpr int kDeadHealthThreshold = 0;        ///< Absolute minimum health before a plant is considered dead.
} // namespace PlantStateThresholds

#endif // PLANT_STATE_THRESHOLDS_H
