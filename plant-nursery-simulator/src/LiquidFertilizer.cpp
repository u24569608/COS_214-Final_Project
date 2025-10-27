#include "../include/LiquidFertilizer.h"
#include "../include/PlantInstance.h"
#include <iostream>
#include <algorithm>

LiquidFertilizer::LiquidFertilizer() {}

void LiquidFertilizer::fertilize(PlantInstance& plant) const {
    int newNutrients = std::min(100, plant.getNutrientLevel() + 40);
    int newHealth = std::min(100, plant.getHealth() + 4);

    plant.setHealth(newHealth);
    std::cout << "[LiquidFertilizer] " << plant.getPlantTypeName()
              << " fertilized with liquid nutrients (+40 nutrients, +4 health)" << std::endl;
}

FertilizeStrategy* LiquidFertilizer::clone() const {
    return new LiquidFertilizer(*this);
}
