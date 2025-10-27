#include "../include/DeadState.h"
#include "../include/PlantInstance.h"

std::string DeadState::getName() const {
    return "Dead";
}

void DeadState::onWater(PlantInstance& plant) {
    (void)plant;
}

void DeadState::onFertilize(PlantInstance& plant) {
    (void)plant;
}

void DeadState::onTick(PlantInstance& plant) {
    (void)plant;
}
