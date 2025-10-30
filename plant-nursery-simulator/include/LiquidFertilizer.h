#ifndef LIQUID_FERTILIZER_H
#define LIQUID_FERTILIZER_H

#include "FertilizeStrategy.h"

/**
 * @file LiquidFertilizer.h
 * @brief Concrete strategy for liquid fertilizing.
 */
class LiquidFertilizer : public FertilizeStrategy {
public:
    /**
     * @brief Creates a strategy that applies liquid nutrients.
     */
    LiquidFertilizer();

    /**
     * @brief Executes the liquid fertilisation process on a plant.
     * @param plant Plant instance receiving nutrients.
     */
    void fertilize(PlantInstance& plant) const override;

    /**
     * @brief Produces a deep copy of the strategy object.
     * @return Newly allocated strategy instance.
     */
    FertilizeStrategy* clone() const override;
};

#endif // LIQUID_FERTILIZER_H
