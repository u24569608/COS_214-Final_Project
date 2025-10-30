#ifndef ORGANIC_FERTILIZER_H
#define ORGANIC_FERTILIZER_H

#include "FertilizeStrategy.h"

/**
 * @file OrganicFertilizer.h
 * @brief Concrete strategy for organic fertilizing.
 */
class OrganicFertilizer : public FertilizeStrategy {
public:
    /**
     * @brief Configures a strategy that applies organic nutrients.
     */
    OrganicFertilizer();

    /**
     * @brief Executes organic fertilisation logic for the given plant.
     * @param plant Plant instance to enrich.
     */
    void fertilize(PlantInstance& plant) const override;

    /**
     * @brief Clones the strategy implementation for reuse.
     * @return Newly allocated strategy instance.
     */
    FertilizeStrategy* clone() const override;
};

#endif // ORGANIC_FERTILIZER_H
