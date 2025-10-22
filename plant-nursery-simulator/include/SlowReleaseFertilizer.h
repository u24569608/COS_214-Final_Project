#ifndef SLOW_RELEASE_FERTILIZER_H
#define SLOW_RELEASE_FERTILIZER_H

#include "FertilizeStrategy.h"

/**
 * @file SlowReleaseFertilizer.h
 * @brief Concrete strategy for slow-release fertilizing.
 */
class SlowReleaseFertilizer : public FertilizeStrategy {
public:
    SlowReleaseFertilizer();
    void fertilize(PlantInstance& plant) const override;
    void clone();
};

#endif // SLOW_RELEASE_FERTILIZER_H