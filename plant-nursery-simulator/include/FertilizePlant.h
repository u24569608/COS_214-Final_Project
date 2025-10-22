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
    FertilizePlant(PlantInstance* p);
    void handleRequest() override;
};

#endif // FERTILIZE_PLANT_H