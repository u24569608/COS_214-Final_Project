#ifndef FREQUENT_WATERING_H
#define FREQUENT_WATERING_H

#include "WaterStrategy.h"

/**
 * @file FrequentWatering.h
 * @brief Concrete strategy for frequent watering.
 */
class FrequentWatering : public WaterStrategy {
public:
    FrequentWatering();
    void water(PlantInstance& plant) const override;
    WaterStrategy* clone() const override;
};

#endif // FREQUENT_WATERING_H