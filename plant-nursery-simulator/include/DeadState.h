#ifndef DEAD_STATE_H
#define DEAD_STATE_H

#include "PlantState.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file DeadState.h
 * @brief Concrete state representing a dead plant.
 */
class DeadState : public PlantState {
public:
    /**
     * @brief Retrieves the friendly state name.
     * @return Constant string "Dead".
     */
    std::string getName() const override;

    /**
     * @brief Handles watering requests; no-op for dead plants.
     * @param plant Context plant instance (unused).
     */
    void onWater(PlantInstance& plant) override;

    /**
     * @brief Handles fertilising requests; no-op for dead plants.
     * @param plant Context plant instance (unused).
     */
    void onFertilize(PlantInstance& plant) override;

    /**
     * @brief Handles tick events; dead plants remain unchanged.
     * @param plant Context plant instance (unused).
     */
    void onTick(PlantInstance& plant) override;
};

#endif // DEAD_STATE_H
