#include "../include/SparseWatering.h"
#include "../include/PlantInstance.h"
#include <iostream>

SparseWatering::SparseWatering() {}

void SparseWatering::water(PlantInstance& plant) const {
    int newWater = plant.getWaterLevel() + 15;
    int newHealth = plant.getHealth() + 1;

    plant.setWaterLevel(newWater);
    plant.setHealth(newHealth);
    std::cout << "[SparseWatering] " << plant.getPlantTypeName()
              << " lightly watered (+15 water, +1 health)" << std::endl;
}

WaterStrategy* SparseWatering::clone() const {
    return new SparseWatering(*this);
}
