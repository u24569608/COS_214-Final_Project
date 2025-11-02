#ifndef FERTILIZE_PLANT_H
#define FERTILIZE_PLANT_H

#include "PlantCommand.h"

// Forward declaration
class PlantInstance;

/**
 * @file FertilizePlant.h
 * @brief A 'ConcreteCommand' to fertilize a plant.
 */
class FertilizePlant : public PlantCommand {
public:
    /**
     * @brief Creates a command bound to a particular plant instance.
     * @param p Plant subject that should be fertilised when executed.
     */
    FertilizePlant(PlantInstance* p);

    /**
     * @brief Executes the fertilisation behaviour on the target plant.
     */
    void handleRequest() override;
};

#endif // FERTILIZE_PLANT_H
