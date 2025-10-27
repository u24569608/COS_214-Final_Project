#include "../include/SlowReleaseFertilizer.h"
#include "../include/PlantInstance.h"
#include <iostream>
#include <algorithm>

SlowReleaseFertilizer::SlowReleaseFertilizer() {}

void SlowReleaseFertilizer::fertilize(PlantInstance& plant) const {
    int newNutrients = std::min(100, plant.getNutrientLevel() + 25);
    int newHealth = std::min(100, plant.getHealth() + 3);

    plant.setHealth(newHealth);
    std::cout << "[SlowReleaseFertilizer] " << plant.getPlantTypeName()
              << " fertilized slowly (+25 nutrients, +3 health)" << std::endl;
}

FertilizeStrategy* SlowReleaseFertilizer::clone() const {
    return new SlowReleaseFertilizer(*this);
}
