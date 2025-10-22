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
    void fertilize(PlantInstance& plant) const override;
    void clone();
};

#endif // ORGANIC_FERTILIZER_H