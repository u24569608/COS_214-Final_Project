#ifndef ORGANIC_FERTILIZER_H
#define ORGANIC_FERTILIZER_H

#include "FertilizeStrategy.h"

/**
 * @file OrganicFertilizer.h
 * @brief Concrete strategy for organic fertilizing.
 */
class OrganicFertilizer : public FertilizeStrategy {
public:
    OrganicFertilizer();
    void fertilize() const override;
};

#endif // ORGANIC_FERTILIZER_H