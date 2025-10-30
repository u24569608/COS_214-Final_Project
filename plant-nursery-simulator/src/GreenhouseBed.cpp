/**
 * @file GreenhouseBed.cpp
 * @brief Implements the GreenhouseBed behaviour defined in the corresponding header.
 */

#include "../include/GreenhouseBed.h"
#include "../include/GreenhouseComponent.h"
#include "../include/GreenhouseIterator.h"
#include "../include/ConcreteGreenhouseIterator.h"
#include "../include/PlantInstance.h"

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
    add(std::unique_ptr<GreenhouseComponent>(component));
}

void GreenhouseBed::remove(GreenhouseComponent* component) {
    release(component);
}

void GreenhouseBed::performCare() {
    for (const std::unique_ptr<GreenhouseComponent>& child : children) {
        if (child) {
            child->performCare();
        }
    }
}

GreenhouseComponent* GreenhouseBed::findPlantInBed(std::string plantName) {
    for (const std::unique_ptr<GreenhouseComponent>& child : children) {
        if (!child) {
            continue;
        }
        if (child->getName() == plantName) {
            return child.get();
        }

        if (auto* nestedBed = dynamic_cast<GreenhouseBed*>(child.get())) {
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

GreenhouseComponent* GreenhouseBed::add(std::unique_ptr<GreenhouseComponent> component) {
    if (!component) {
        return nullptr;
    }
    GreenhouseComponent* rawPtr = component.get();
    const auto alreadyPresent = std::find_if(children.begin(), children.end(),
        [rawPtr](const std::unique_ptr<GreenhouseComponent>& existing) {
            return existing.get() == rawPtr;
        });
    if (alreadyPresent != children.end()) {
        component.release();
        return rawPtr;
    }
    children.push_back(std::move(component));
    return rawPtr;
}

std::unique_ptr<GreenhouseComponent> GreenhouseBed::release(GreenhouseComponent* component) {
    if (!component) {
        return nullptr;
    }

    auto it = std::find_if(children.begin(), children.end(),
        [component](const std::unique_ptr<GreenhouseComponent>& current) {
            return current.get() == component;
        });

    if (it == children.end()) {
        return nullptr;
    }

    std::unique_ptr<GreenhouseComponent> released = std::move(*it);
    children.erase(it);
    return released;
}

std::unique_ptr<PlantInstance> GreenhouseBed::releasePlant(PlantInstance* plant) {
    std::unique_ptr<GreenhouseComponent> component = release(plant);
    if (!component) {
        return nullptr;
    }

    PlantInstance* rawPlant = dynamic_cast<PlantInstance*>(component.get());
    if (!rawPlant) {
        // Restore ownership to avoid losing the component.
        add(std::move(component));
        return nullptr;
    }

    component.release();
    return std::unique_ptr<PlantInstance>(rawPlant);
}
