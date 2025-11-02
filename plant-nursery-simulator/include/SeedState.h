#ifndef SEED_STATE_H
#define SEED_STATE_H

#include "PlantState.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file SeedState.h
 * @brief Concrete state representing a seed.
 */
class SeedState : public PlantState {
public:
    /**
     * @brief Retrieves the friendly state name.
     * @return Constant string "Seed".
     */
    std::string getName() const override;

    /**
     * @brief Applies watering logic for a seed.
     * @param plant Context plant instance receiving water.
     */
    void onWater(PlantInstance& plant) override;

    /**
     * @brief Applies fertilising logic for a seed.
     * @param plant Context plant instance receiving nutrients.
     */
    void onFertilize(PlantInstance& plant) override;

    /**
     * @brief Updates the seed state at the end of a tick.
     * @param plant Context plant instance whose vitals may change.
     */
    void onTick(PlantInstance& plant) override;
};

#endif // SEED_STATE_H
