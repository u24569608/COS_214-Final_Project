#include "../include/FrequentWatering.h"
#include "../include/PlantInstance.h"
#include <iostream>

FrequentWatering::FrequentWatering() {}

void FrequentWatering::water(PlantInstance& plant) const {
    int newWater = plant.getWaterLevel() + 35;
    int newHealth = plant.getHealth() + 3;

    plant.setWaterLevel(newWater);
    plant.setHealth(newHealth);
    std::cout << "[FrequentWatering] " << plant.getPlantTypeName()
              << " watered frequently (+35 water, +3 health)" << std::endl;
}

WaterStrategy* FrequentWatering::clone() const {
    return new FrequentWatering(*this);
}
