#ifndef WITHERING_STATE_H
#define WITHERING_STATE_H

#include "PlantState.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file WitheringState.h
 * @brief Concrete state representing a withering plant (needs care).
 */
class WitheringState : public PlantState {
public:
    /**
     * @brief Retrieves the friendly state name.
     * @return Constant string "Withering".
     */
    std::string getName() const override;

    /**
     * @brief Handles watering while the plant is withering.
     * @param plant Context plant instance receiving water.
     */
    void onWater(PlantInstance& plant) override;

    /**
     * @brief Handles fertilising while the plant is withering.
     * @param plant Context plant instance receiving nutrients.
     */
    void onFertilize(PlantInstance& plant) override;

    /**
     * @brief Updates withering progress during a tick.
     * @param plant Context plant instance being advanced.
     */
    void onTick(PlantInstance& plant) override;
};

#endif // WITHERING_STATE_H
