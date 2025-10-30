/**
 * @file PlantCommand.cpp
 * @brief Implements the PlantCommand behaviour defined in the corresponding header.
 */

#include "../include/PlantCommand.h"

PlantCommand::PlantCommand(PlantInstance* p) {
    this->plant = p;
}

PlantCommand::~PlantCommand() = default;