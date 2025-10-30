/**
 * @file WaterPlant.cpp
 * @brief Implements the WaterPlant behaviour defined in the corresponding header.
 */

#include "../include/PlantInstance.h"
#include "../include/WaterPlant.h"
#include <iostream>

WaterPlant::WaterPlant(PlantInstance* p) : PlantCommand(p) {
    
}

void WaterPlant::handleRequest() {
    if (this->plant == nullptr) {
        std::cerr << "[WaterPlant] Plant is NULL. Cannot Execute." << std::endl;
        return;
    }
    
    this->plant->performWater();
}