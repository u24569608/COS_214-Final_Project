/**
 * @file PlantPrototypeRegistry.cpp
 * @brief Implementation of the PlantPrototypeRegistry class.
 */
#include "PlantPrototypeRegistry.h"
#include "Plant.h"
#include <iostream>

PlantPrototypeRegistry::PlantPrototypeRegistry() {
}

PlantPrototypeRegistry::~PlantPrototypeRegistry() {
    // unique_ptr automatically handles deleting the stored prototypes
}

void PlantPrototypeRegistry::addPrototype(std::string name, Plant* plant) {
    prototypes[name] = std::unique_ptr<Plant>(plant);
}

Plant* PlantPrototypeRegistry::createPlant(std::string name, std::string type) {

    auto it = prototypes.find(name);
    
    if (it != prototypes.end()) {
        // Found: call clone() on the stored prototype
        return it->second->clone();
    }
    
    // Not found
    std::cerr << "Error: Prototype '" << name << "' not found in registry." << std::endl;
    return nullptr;
}