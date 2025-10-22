#ifndef WATER_STRATEGY_H
#define WATER_STRATEGY_H

class PlantInstance;

/**
 * @file WaterStrategy.h
 * @brief Abstract 'Strategy' interface for watering. (FR5)
 */
class WaterStrategy {
public:
    virtual ~WaterStrategy();
    /**
     * @brief Abstract method to execute the watering strategy.
     */
    virtual void water(PlantInstance& plant) const = 0;
    virtual void clone() = 0;
    
};

#endif // WATER_STRATEGY_H