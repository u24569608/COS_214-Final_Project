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
    void fertilize() const override;
};

#endif // LIQUID_FERTILIZER_H