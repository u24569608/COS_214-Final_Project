#ifndef SLOW_RELEASE_H
#define SLOW_RELEASE_H

#include "FertilizeStrategy.h"

/**
 * @file SlowRelease.h
 * @brief Concrete strategy for slow-release fertilizing.
 */
class SlowRelease : public FertilizeStrategy {
public:
    SlowRelease();
    void fertilize() const override;
};

#endif // SLOW_RELEASE_H