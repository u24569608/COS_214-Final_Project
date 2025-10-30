#ifndef SEASONAL_WATERING_H
#define SEASONAL_WATERING_H

#include "WaterStrategy.h"

/**
 * @file SeasonalWatering.h
 * @brief Concrete strategy for seasonal watering.
 */
class SeasonalWatering : public WaterStrategy {
public:
    /**
     * @brief Creates a strategy that adapts watering intensity to the season.
     */
    SeasonalWatering();

    /**
     * @brief Applies the seasonal watering routine to the plant.
     * @param plant Plant instance to hydrate.
     */
    void water(PlantInstance& plant) const override;

    /**
     * @brief Produces a copy of this strategy implementation.
     * @return Newly allocated strategy instance.
     */
    WaterStrategy* clone() const override;
};

#endif // SEASONAL_WATERING_H
