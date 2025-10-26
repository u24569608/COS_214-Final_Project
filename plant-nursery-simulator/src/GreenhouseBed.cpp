#include "../include/GreenhouseBed.h"
#include "../include/GreenhouseComponent.h"
#include "../include/GreenhouseIterator.h"
#include "../include/ConcreteGreenhouseIterator.h"

#include <algorithm>
#include <memory>
#include <utility>

GreenhouseBed::GreenhouseBed()
    : GreenhouseComponent("Unnamed Bed") {
    // No-op
}

GreenhouseBed::GreenhouseBed(std::string bedName)
    : GreenhouseComponent(std::move(bedName)) {
    // No-op
}

void GreenhouseBed::add(GreenhouseComponent* component) {
    if (!component) {
        return;
    }
    if (std::find(children.begin(), children.end(), component) == children.end()) {
        children.push_back(component);
    }
}

void GreenhouseBed::remove(GreenhouseComponent* component) {
    if (!component) {
        return;
    }
    auto it = std::remove(children.begin(), children.end(), component);
    if (it != children.end()) {
        children.erase(it, children.end());
    }
}

void GreenhouseBed::performCare() {
    for (GreenhouseComponent* child : children) {
        if (child) {
            child->performCare();
        }
    }
}

GreenhouseComponent* GreenhouseBed::findPlantInBed(std::string plantName) {
    for (GreenhouseComponent* child : children) {
        if (!child) {
            continue;
        }
        if (child->getName() == plantName) {
            return child;
        }

        if (auto* nestedBed = dynamic_cast<GreenhouseBed*>(child)) {
            if (GreenhouseComponent* found = nestedBed->findPlantInBed(plantName)) {
                return found;
            }
        }
    }
    return nullptr;
}

int GreenhouseBed::getSize() const {
    return static_cast<int>(children.size());
}

std::unique_ptr<GreenhouseIterator> GreenhouseBed::createIterator() {
    return std::make_unique<ConcreteGreenhouseIterator>(this);
}
