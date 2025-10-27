#ifndef PLANT_STATE_THRESHOLDS_H
#define PLANT_STATE_THRESHOLDS_H

/**
 * @file PlantStateThresholds.h
 * @brief Centralised constants describing lifecycle transition boundaries.
 */
namespace PlantStateThresholds {
constexpr int kSeedToGrowingWater = 60;
constexpr int kSeedToGrowingNutrients = 55;
constexpr int kSeedToGrowingHealth = 70;

constexpr int kGrowingToMatureHealth = 85;
constexpr int kGrowingToMatureWater = 70;
constexpr int kGrowingToMatureNutrients = 70;

constexpr int kMatureHealthFloor = 60;

constexpr int kWitheringWaterThreshold = 35;
constexpr int kWitheringNutrientThreshold = 30;
constexpr int kWitheringRecoveryHealth = 65;
constexpr int kWitheringCriticalHealth = 20;

constexpr int kDeadHealthThreshold = 0;
} // namespace PlantStateThresholds

#endif // PLANT_STATE_THRESHOLDS_H
