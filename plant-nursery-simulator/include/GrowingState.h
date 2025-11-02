#ifndef GROWING_STATE_H
#define GROWING_STATE_H

#include "PlantState.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file GrowingState.h
 * @brief Concrete state representing a growing plant.
 */
class GrowingState : public PlantState {
public:
    /**
     * @brief Retrieves the friendly state name.
     * @return Constant string "Growing".
     */
    std::string getName() const override;

    /**
     * @brief Handles watering while the plant is growing.
     * @param plant Context plant instance receiving water.
     */
    void onWater(PlantInstance& plant) override;

    /**
     * @brief Handles fertilising while the plant is growing.
     * @param plant Context plant instance receiving nutrients.
     */
    void onFertilize(PlantInstance& plant) override;

    /**
     * @brief Updates growth progress during a tick.
     * @param plant Context plant instance being advanced.
     */
    void onTick(PlantInstance& plant) override;
};

#endif // GROWING_STATE_H
