#ifndef PLANT_STATE_H
#define PLANT_STATE_H

#include <string>

// Forward declaration for the 'Context' class
class PlantInstance; 

/**
 * @file PlantState.h
 * @brief The abstract 'State' base class for the State pattern.
 * @details Defines the interface for all plant life-cycle states.
 * This version is updated based on the new function list.
 */
class PlantState {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~PlantState();

    /**
     * @brief Gets the friendly name of the current state.
     * @return std::string The name (e.g., "Growing", "Mature").
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Public handle method for a water event.
     * @param plant The context (the plant) to affect.
     */
    virtual void onWater(PlantInstance& plant) = 0;

    /**
     * @brief Public handle method for a fertilize event.
     * @param plant The context (the plant) to affect.
     */
    virtual void onFertilize(PlantInstance& plant) = 0;

    /**
     * @brief Public handle method for a time 'tick' (e.g., a day passes).
     * @param plant The context (the plant) to affect.
     */
    virtual void onTick(PlantInstance& plant) = 0;

private:
    /**
     * @brief Private helper to perform the actual watering logic.
     * @param plant The context (the plant) to affect.
     */
    virtual void performWater(PlantInstance& plant) = 0;

    /**
     * @brief Private helper to perform the actual fertilizing logic.
     * @param plant The context (the plant) to affect.
     */
    virtual void performFertilize(PlantInstance& plant) = 0;
};

#endif // PLANT_STATE_H

