#ifndef WATER_STRATEGY_H
#define WATER_STRATEGY_H

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
    virtual void water() const = 0;
};

#endif // WATER_STRATEGY_H