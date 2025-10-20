#ifndef WATER_PLANT_H
#define WATER_PLANT_H

#include "PlantCommand.h"

// Forward declaration
class PlantInstance;

/**
 * @file WaterPlant.h
 * @brief A 'ConcreteCommand' to water a plant.
 */
class WaterPlant : public PlantCommand {
public:
    WaterPlant(PlantInstance* p);
    void execute() override;
};

#endif // WATER_PLANT_H