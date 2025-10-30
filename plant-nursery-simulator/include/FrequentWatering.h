#ifndef FREQUENT_WATERING_H
#define FREQUENT_WATERING_H

#include "WaterStrategy.h"

/**
 * @file FrequentWatering.h
 * @brief Concrete strategy for frequent watering.
 */
class FrequentWatering : public WaterStrategy {
public:
    /**
     * @brief Configures a strategy that waters plants on a short cadence.
     */
    FrequentWatering();

    /**
     * @brief Applies a frequent watering regime to the supplied plant.
     * @param plant Plant instance that should be hydrated.
     */
    void water(PlantInstance& plant) const override;

    /**
     * @brief Produces a copy of this strategy implementation.
     * @return Newly allocated strategy instance.
     */
    WaterStrategy* clone() const override;
};

#endif // FREQUENT_WATERING_H
