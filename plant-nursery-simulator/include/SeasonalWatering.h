#ifndef SEASONAL_WATERING_H
#define SEASONAL_WATERING_H

#include "WaterStrategy.h"

/**
 * @file SeasonalWatering.h
 * @brief Concrete strategy for seasonal watering.
 */
class SeasonalWatering : public WaterStrategy {
public:
    SeasonalWatering();
    void water() const override;
};

#endif // SEASONAL_WATERING_H