#include "../include/OrganicFertilizer.h"
#include "../include/PlantInstance.h"
#include <iostream>
#include <algorithm>

OrganicFertilizer::OrganicFertilizer() {}

void OrganicFertilizer::fertilize(PlantInstance& plant) const {
    int newNutrients =  plant.getNutrientLevel() + 30;
    int newHealth =  plant.getHealth() + 5;

    plant.setNutrientLevel(newNutrients);
    plant.setHealth(newHealth);
    std::cout << "[OrganicFertilizer] " << plant.getPlantTypeName()
              << " fertilized organically (+30 nutrients, +5 health)" << std::endl;
}

FertilizeStrategy* OrganicFertilizer::clone() const {
    return new OrganicFertilizer(*this);
}
