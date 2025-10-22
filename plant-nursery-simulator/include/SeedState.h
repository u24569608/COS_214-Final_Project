#ifndef SEED_STATE_H
#define SEED_STATE_H

#include "PlantState.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file SeedState.h
 * @brief Concrete state representing a seed.
 */
class SeedState : public PlantState {
public:
    SeedState();

    std::string getName() const override;
    void onWater(PlantInstance& plant) override;
    void onFertilize(PlantInstance& plant) override;
    void onTick(PlantInstance& plant) override;

private:
    void performWater(PlantInstance& plant) override;
    void performFertilize(PlantInstance& plant) override;
};

#endif // SEED_STATE_H

