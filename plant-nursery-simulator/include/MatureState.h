#ifndef MATURE_STATE_H
#define MATURE_STATE_H

#include "PlantState.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file MatureState.h
 * @brief Concrete state representing a mature plant (ready for sale).
 */
class MatureState : public PlantState {
public:
    /**
     * @brief Retrieves the friendly state name.
     * @return Constant string "Mature".
     */
    std::string getName() const override;

    /**
     * @brief Handles watering for a mature plant.
     * @param plant Context plant instance receiving water.
     */
    void onWater(PlantInstance& plant) override;

    /**
     * @brief Handles fertilising for a mature plant.
     * @param plant Context plant instance receiving nutrients.
     */
    void onFertilize(PlantInstance& plant) override;

    /**
     * @brief Updates maturity state during a tick.
     * @param plant Context plant instance being advanced.
     */
    void onTick(PlantInstance& plant) override;

    /**
     * @brief Mature plants are ready for sale.
     */
    bool isMarketReady() const override;
};

#endif // MATURE_STATE_H
