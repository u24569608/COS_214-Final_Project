#include "../include/SlowReleaseFertilizer.h"
#include "../include/PlantInstance.h"
#include <iostream>

SlowReleaseFertilizer::SlowReleaseFertilizer() {}

void SlowReleaseFertilizer::fertilize(PlantInstance& plant) const {
    int newNutrients = plant.getNutrientLevel() + 25;
    int newHealth = plant.getHealth() + 3;

    plant.setNutrientLevel(newNutrients);
    plant.setHealth(newHealth);
    std::cout << "[SlowReleaseFertilizer] " << plant.getPlantTypeName()
              << " fertilized slowly (+25 nutrients, +3 health)" << std::endl;
}

FertilizeStrategy* SlowReleaseFertilizer::clone() const {
    return new SlowReleaseFertilizer(*this);
}
