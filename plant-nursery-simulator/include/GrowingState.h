#ifndef GROWING_STATE_H
#define GROWING_STATE_H

#include "PlantState.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file GrowingState.h
 * @brief Concrete state representing a growing plant.
 */
class GrowingState : public PlantState {
public:
    GrowingState();

    std::string getName() const override;
    void onWater(PlantInstance& plant) override;
    void onFertilize(PlantInstance& plant) override;
    void onTick(PlantInstance& plant) override;

private:
    void performWater(PlantInstance& plant) override;
    void performFertilize(PlantInstance& plant) override;
};

#endif // GROWING_STATE_H

