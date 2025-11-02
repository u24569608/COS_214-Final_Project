/**
 * @file FertilizePlant.cpp
 * @brief Implements the FertilizePlant behaviour defined in the corresponding header.
 */

#include "../include/PlantInstance.h"
#include "../include/FertilizePlant.h"
#include <iostream>

FertilizePlant::FertilizePlant(PlantInstance* p) : PlantCommand(p) {

}

void FertilizePlant::handleRequest() {
    if (this->plant == nullptr) {
        std::cerr << "[FertilizePlant] Plant is NULL. Cannot Execute." << std::endl;
        return;
    }
    
    this->plant->performFertilize();
}
