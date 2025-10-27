#include "../include/PlantPrototypeRegistry.h"
#include "../include/Plant.h"

#include <utility>

PlantPrototypeRegistry::PlantPrototypeRegistry() = default;

PlantPrototypeRegistry::~PlantPrototypeRegistry() = default;

void PlantPrototypeRegistry::addPrototype(const std::string& name, std::unique_ptr<Plant> plant) {
    if (name.empty() || !plant) {
        return;
    }

    prototypes[name] = std::move(plant);
}

Plant* PlantPrototypeRegistry::createPlant(const std::string& name, const std::string& type) {
    auto it = prototypes.find(name);
    if (it == prototypes.end() || it->second == nullptr) {
        return nullptr;
    }

    Plant* clone = it->second->clone();
    if (clone == nullptr) {
        return nullptr;
    }

    if (!type.empty()) {
        clone->setType(type);
    }

    return clone;
}

bool PlantPrototypeRegistry::hasPrototype(const std::string& name) const {
    auto it = prototypes.find(name);
    return it != prototypes.end() && it->second != nullptr;
}
