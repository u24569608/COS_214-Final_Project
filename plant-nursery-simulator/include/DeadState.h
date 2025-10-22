#ifndef DEAD_STATE_H
#define DEAD_STATE_H

#include "PlantState.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file DeadState.h
 * @brief Concrete state representing a dead plant.
 */
class DeadState : public PlantState {
public:
    DeadState();

    std::string getName() const override;
    void onWater(PlantInstance& plant) override;
    void onFertilize(PlantInstance& plant) override;
    void onTick(PlantInstance& plant) override;

private:
    void performWater(PlantInstance& plant) override;
    void performFertilize(PlantInstance& plant) override;
};

#endif // DEAD_STATE_H

