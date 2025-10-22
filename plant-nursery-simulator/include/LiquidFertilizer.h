#ifndef LIQUID_FERTILIZER_H
#define LIQUID_FERTILIZER_H

#include "FertilizeStrategy.h"

/**
 * @file LiquidFertilizer.h
 * @brief Concrete strategy for liquid fertilizing.
 */
class LiquidFertilizer : public FertilizeStrategy {
public:
    LiquidFertilizer();
    void fertilize(PlantInstance& plant) const override;
    void clone();
};

#endif // LIQUID_FERTILIZER_H