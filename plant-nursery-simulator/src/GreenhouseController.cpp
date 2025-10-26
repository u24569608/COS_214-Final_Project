#include "../include/GreenhouseController.h"

#include "../include/GreenhouseIterator.h"
#include "../include/PlantInstance.h"

#include <memory>

GreenhouseController::GreenhouseController(GreenhouseBed* root)
    : rootBed(root) {
}

void GreenhouseController::setRootBed(GreenhouseBed* root) {
    rootBed = root;
}

void GreenhouseController::runGrowthTick() {
    if (!rootBed) {
        return;
    }

    std::unique_ptr<GreenhouseIterator> iterator = rootBed->createIterator();
    if (!iterator) {
        return;
    }

    for (PlantInstance* plant = iterator->first(); plant != nullptr; plant = iterator->next()) {
        plant->applyGrowthTick();
        // plant->performCare(); //TODO: Where is the care action supposed to be invoked?
    }
}

