#include "../include/ConcreteGreenhouseIterator.h"

#include "../include/GreenhouseBed.h"
#include "../include/GreenhouseComponent.h"
#include "../include/PlantInstance.h"

ConcreteGreenhouseIterator::ConcreteGreenhouseIterator(GreenhouseBed* root)
    : rootBed(root),
      traversalOrder(),
      currentIndex(0U) {
    collectPlants(rootBed);
}

PlantInstance* ConcreteGreenhouseIterator::first() {
    currentIndex = 0U;
    if (traversalOrder.empty()) {
        return nullptr;
    }
    return traversalOrder[currentIndex];
}

PlantInstance* ConcreteGreenhouseIterator::next() {
    if (traversalOrder.empty()) {
        return nullptr;
    }
    if (currentIndex + 1U < traversalOrder.size()) {
        ++currentIndex;
        return traversalOrder[currentIndex];
    }
    currentIndex = traversalOrder.size();
    return nullptr;
}

bool ConcreteGreenhouseIterator::hasNext() const {
    return currentIndex < traversalOrder.size();
}

PlantInstance* ConcreteGreenhouseIterator::currentItem() const {
    if (currentIndex < traversalOrder.size()) {
        return traversalOrder[currentIndex];
    }
    return nullptr;
}

void ConcreteGreenhouseIterator::collectPlants(GreenhouseComponent* component) {
    if (!component) {
        return;
    }

    if (auto* plant = dynamic_cast<PlantInstance*>(component)) {
        traversalOrder.push_back(plant);
        return;
    }

    if (auto* bed = dynamic_cast<GreenhouseBed*>(component)) {
        for (GreenhouseComponent* child : bed->children) {
            collectPlants(child);
        }
    }
}
