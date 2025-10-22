#ifndef WITHERING_STATE_H
#define WITHERING_STATE_H

#include "PlantState.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file WitheringState.h
 * @brief Concrete state representing a withering plant (needs care).
 */
class WitheringState : public PlantState {
public:
    WitheringState();

    std::string getName() const override;
    void onWater(PlantInstance& plant) override;
    void onFertilize(PlantInstance& plant) override;
    void onTick(PlantInstance& plant) override;

private:
    void performWater(PlantInstance& plant) override;
    void performFertilize(PlantInstance& plant) override;
};

#endif // WITHERING_STATE_H

