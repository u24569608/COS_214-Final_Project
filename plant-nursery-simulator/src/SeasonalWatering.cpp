#include "../include/SeasonalWatering.h"
#include "../include/PlantInstance.h"
#include <iostream>
#include <algorithm>
#include <ctime>

SeasonalWatering::SeasonalWatering() {}

void SeasonalWatering::water(PlantInstance& plant) const {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    int month = localTime->tm_mon + 1;

    // Spring boost: September–November in South Africa
    int waterBoost = (month >= 9 && month <= 11) ? 40 : 20;
    int newWater =  plant.getWaterLevel() + waterBoost;
    int newHealth = plant.getHealth() + 2;

    plant.setWaterLevel(newWater);
    plant.setHealth(newHealth);
    std::cout << "[SeasonalWatering] " << plant.getPlantTypeName()
              << " watered seasonally (+" << waterBoost
              << " water, +2 health)" << std::endl;
}

WaterStrategy* SeasonalWatering::clone() const {
    return new SeasonalWatering(*this);
}
