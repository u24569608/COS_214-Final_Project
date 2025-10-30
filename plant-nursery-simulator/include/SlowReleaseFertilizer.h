#ifndef SLOW_RELEASE_FERTILIZER_H
#define SLOW_RELEASE_FERTILIZER_H

#include "FertilizeStrategy.h"

/**
 * @file SlowReleaseFertilizer.h
 * @brief Concrete strategy for slow-release fertilizing.
 */
class SlowReleaseFertilizer : public FertilizeStrategy {
public:
    /**
     * @brief Creates a fertilisation strategy that releases nutrients gradually.
     */
    SlowReleaseFertilizer();

    /**
     * @brief Applies the slow-release nutrient schedule to the plant.
     * @param plant Plant instance being fertilised.
     */
    void fertilize(PlantInstance& plant) const override;

    /**
     * @brief Produces a deep copy of this strategy implementation.
     * @return Newly allocated strategy instance.
     */
    FertilizeStrategy* clone() const override;
};

#endif // SLOW_RELEASE_FERTILIZER_H
