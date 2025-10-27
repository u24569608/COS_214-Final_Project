#include "../include/SparseWatering.h"
#include "../include/PlantInstance.h"
#include <iostream>
#include <algorithm>

SparseWatering::SparseWatering() {}

void SparseWatering::water(PlantInstance& plant) const {
    int newWater = std::min(100, plant.getWaterLevel() + 15);
    int newHealth = std::min(100, plant.getHealth() + 1);

    plant.setHealth(newHealth);
    std::cout << "[SparseWatering] " << plant.getPlantTypeName()
              << " lightly watered (+15 water, +1 health)" << std::endl;
}

WaterStrategy* SparseWatering::clone() const {
    return new SparseWatering(*this);
}
