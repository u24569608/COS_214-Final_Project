#ifndef PLANT_STATE_H
#define PLANT_STATE_H

#include <string>

class PlantInstance;

/**
 * @file PlantState.h
 * @brief Abstract base class describing the lifecycle state of a plant.
 */
class PlantState {
public:
    /**
     * @brief Virtual default destructor to permit safe polymorphic deletion.
     */
    virtual ~PlantState() = default;

    /**
     * @brief Gets a human-readable name of the state.
     * @return Friendly name such as "Seed" or "Mature".
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Handles watering performed on the owning plant instance.
     * @param plant Context instance whose data should be mutated.
     */
    virtual void onWater(PlantInstance& plant) = 0;

    /**
     * @brief Handles fertilising performed on the owning plant instance.
     * @param plant Context instance whose data should be mutated.
     */
    virtual void onFertilize(PlantInstance& plant) = 0;

    /**
     * @brief Handles the passage of time for the plant.
     * @param plant Context instance whose state should update.
     */
    virtual void onTick(PlantInstance& plant) = 0;
};

#endif // PLANT_STATE_H
