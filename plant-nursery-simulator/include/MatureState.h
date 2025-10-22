#ifndef MATURE_STATE_H
#define MATURE_STATE_H

#include "PlantState.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file MatureState.h
 * @brief Concrete state representing a mature plant (ready for sale).
 */
class MatureState : public PlantState {
public:
    MatureState();

    std::string getName() const override;
    void onWater(PlantInstance& plant) override;
    void onFertilize(PlantInstance& plant) override;
    void onTick(PlantInstance& plant) override;

private:
    void performWater(PlantInstance& plant) override;
    void performFertilize(PlantInstance& plant) override;
};

#endif // MATURE_STATE_H

