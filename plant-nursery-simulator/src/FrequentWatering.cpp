#include "../include/FrequentWatering.h"
#include "../include/PlantInstance.h"
#include <iostream>
#include <algorithm>

FrequentWatering::FrequentWatering() {}

void FrequentWatering::water(PlantInstance& plant) const {
    int newWater = std::min(100, plant.getWaterLevel() + 35);
    int newHealth = std::min(100, plant.getHealth() + 3);

    plant.setHealth(newHealth);
    std::cout << "[FrequentWatering] " << plant.getPlantTypeName()
              << " watered frequently (+35 water, +3 health)" << std::endl;
}

WaterStrategy* FrequentWatering::clone() const {
    return new FrequentWatering(*this);
}