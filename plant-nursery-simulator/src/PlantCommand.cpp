#include "../include/PlantCommand.h"

PlantCommand::PlantCommand(PlantInstance* p) {
    this->plant = p;
}

PlantCommand::~PlantCommand() = default;