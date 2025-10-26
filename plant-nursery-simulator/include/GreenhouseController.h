#ifndef GREENHOUSE_CONTROLLER_H
#define GREENHOUSE_CONTROLLER_H

#include "GreenhouseBed.h"

/**
 * @file GreenhouseController.h
 * @brief The controller responsible for applying periodic care to the nursery.
 */
class GreenhouseController {
public:
    /**
     * @brief Constructs a controller optionally bound to an existing bed hierarchy.
     * @param root Optional pointer to the greenhouse composite that should be managed.
     */
    explicit GreenhouseController(GreenhouseBed* root = nullptr);

    /**
     * @brief Updates the controller to operate on a different root bed.
     * @param root Pointer to the new composite hierarchy (may be nullptr to detach).
     */
    void setRootBed(GreenhouseBed* root);

    /**
     * @brief Triggers a growth tick for every plant and performs follow-up care.
     * @details The method iterates over all plants, applying growth and invoking care actions.
     */
    void runGrowthTick();

private:
    GreenhouseBed* rootBed; ///< Entry point into the composite structure under management.
};

#endif
