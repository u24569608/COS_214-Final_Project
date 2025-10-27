#include "../include/LiquidFertilizer.h"
#include "../include/PlantInstance.h"
#include <iostream>

LiquidFertilizer::LiquidFertilizer() {}

void LiquidFertilizer::fertilize(PlantInstance& plant) const {
    int newNutrients = plant.getNutrientLevel() + 40;
    int newHealth = plant.getHealth() + 4;

    plant.setNutrientLevel(newNutrients);
    plant.setHealth(newHealth);
    std::cout << "[LiquidFertilizer] " << plant.getPlantTypeName()
              << " fertilized with liquid nutrients (+40 nutrients, +4 health)" << std::endl;
}

FertilizeStrategy* LiquidFertilizer::clone() const {
    return new LiquidFertilizer(*this);
}
