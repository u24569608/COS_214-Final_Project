/**
 * @file Inventory.cpp
 * @brief Implements the Inventory behaviour defined in the corresponding header.
 */

#include "../include/Inventory.h"
#include "../include/ConcreteInventoryIterator.h" // For createIterator()
#include "../include/StockItem.h"                 // For item definitions
#include "../include/FileAdapter.h"
#include "../include/GreenhouseBed.h"
#include "../include/PlantPrototypeRegistry.h"
#include "../include/PlantInstance.h"
#include "../include/Plant.h"
#include <algorithm>                   // For std::find_if, std::remove_if
#include <iostream>

namespace {
std::string plantCounterKey(const std::string& plantName) {
    return plantName.empty() ? "Plant" : plantName;
}
} // namespace

Inventory::Inventory()
    : greenhouseRoot(nullptr),
      plantRegistry(nullptr) {
}

Inventory::~Inventory() {
    itemsById.clear();
    releaseManagedPlants();
    plantInstanceCounters.clear();
}

/**
 * @brief createIterator: Create and return a new iterator.
 * This is the core of the Iterator pattern.
 */
InventoryIterator* Inventory::createIterator() {
    // Pass 'this' (a pointer to this Inventory instance)
    // to the iterator so it knows what to iterate over.
    return new ConcreteInventoryIterator(this);
}

void Inventory::additem(std::unique_ptr<StockItem> item) {
    if (!item) {
        return;
    }
    StockItem* rawItem = item.get();
    itemsById[rawItem->getId()] = rawItem;
    registerPlant(rawItem->getplant(), false);
    items.push_back(std::move(item));
}

void Inventory::removeItem(std::string name) {
    // 1. Find the first item that matches the name
    auto it = std::find_if(items.begin(), items.end(),
        [&name](const std::unique_ptr<StockItem>& item) {
            return item->getname() == name;
        });

    // 2. If we found it, delete and erase
    if (it != items.end()) {
        const std::string itemId = (*it)->getId();
        removeItemById(itemId);
    }
}

int Inventory::getStockCount(std::string plantType) const {
    return static_cast<int>(std::count_if(items.begin(),
                                          items.end(),
                                          [&plantType](const std::unique_ptr<StockItem>& item) {
                                              return item->getname() == plantType;
                                          }));
}

StockItem* Inventory::findItem(std::string name) {
    // Use std::find_if from <algorithm> with a lambda
    auto it = std::find_if(items.begin(), items.end(),
        [&name](const std::unique_ptr<StockItem>& item) {
            return item->getname() == name;
        });

    if (it != items.end()) {
        return it->get();
    }
    return nullptr; // Not found
}

StockItem* Inventory::findItemById(const std::string& id) const {
    if (id.empty()) {
        return nullptr;
    }
    auto it = itemsById.find(id);
    if (it == itemsById.end()) {
        return nullptr;
    }
    return it->second;
}

bool Inventory::removeItemById(const std::string& id) {
    if (id.empty()) {
        return false;
    }
    auto mapIt = itemsById.find(id);
    if (mapIt == itemsById.end()) {
        return false;
    }

    StockItem* itemToDelete = mapIt->second;
    if (itemToDelete == nullptr) {
        itemsById.erase(mapIt);
        return false;
    }

    const std::string itemName = itemToDelete->getname();
    PlantInstance* plant = itemToDelete->getplant();

    auto vecIt = std::find_if(items.begin(), items.end(),
                              [itemToDelete](const std::unique_ptr<StockItem>& item) {
                                  return item.get() == itemToDelete;
                              });
    if (vecIt == items.end()) {
        itemsById.erase(mapIt);
        return false;
    }

    std::unique_ptr<StockItem> removed = std::move(*vecIt);
    items.erase(vecIt);
    itemsById.erase(mapIt);
    removed.reset();
    unregisterPlant(plant);
    if (getStockCount(itemName) == 0) {
        plantInstanceCounters.erase(plantCounterKey(itemName));
    }
    return true;
}


/**
 * @brief Delegates loading to the provided adapter after clearing stock and managed greenhouse plants.
 */
void Inventory::loadFromFile(FileAdapter* adapter, std::string filePath) {
    if (adapter == nullptr) {
        std::cerr << "[Inventory] Error: FileAdapter is null." << std::endl;
        return;
    }
    // Clear current inventory before loading
    std::cout << "[Inventory] Clearing current inventory before loading..." << std::endl;
    items.clear();
    itemsById.clear();
    releaseManagedPlants();
    plantInstanceCounters.clear();

    std::cout << "[Inventory] Loading from file: " << filePath << std::endl;
    adapter->loadInventory(filePath, this);
    std::cout << "[Inventory] Load complete. Current stock count: " << items.size() << std::endl;
}

/**
 * @brief Delegates saving to the provided adapter.
 */
void Inventory::saveToFile(FileAdapter* adapter, std::string filePath) {
     if (adapter == nullptr) {
        std::cerr << "[Inventory] Error: FileAdapter is null." << std::endl;
        return;
    }
    std::cout << "[Inventory] Saving current inventory (" << items.size() << " items) to file: " << filePath << std::endl;
    adapter->saveInventory(filePath, this);
    std::cout << "[Inventory] Save complete." << std::endl;
}

void Inventory::setGreenhouseRoot(GreenhouseBed* root) {
    greenhouseRoot = root;
    if (greenhouseRoot == nullptr) {
        return;
    }

    for (auto& plantPtr : pendingPlants) {
        if (!plantPtr) {
            continue;
        }
        PlantInstance* raw = plantPtr.get();
        greenhouseRoot->add(std::move(plantPtr));
        greenhousePlants.insert(raw);
    }
    pendingPlants.clear();
}

GreenhouseBed* Inventory::getGreenhouseRoot() const {
    return greenhouseRoot;
}

void Inventory::setPlantRegistry(PlantPrototypeRegistry* registry) {
    plantRegistry = registry;
}

PlantPrototypeRegistry* Inventory::getPlantRegistry() const {
    return plantRegistry;
}

void Inventory::registerPlantType(const std::string& plantName) {
    if (!plantName.empty()) {
        registeredPlantTypes.insert(plantName);
    }
}

void Inventory::clearPlantTypes() {
    registeredPlantTypes.clear();
}

bool Inventory::isPlantType(const std::string& plantName) const {
    if (plantName.empty()) {
        return false;
    }
    if (registeredPlantTypes.count(plantName) > 0U) {
        return true;
    }
    if (plantRegistry != nullptr) {
        return plantRegistry->hasPrototype(plantName);
    }
    return false;
}

PlantInstance* Inventory::createPlantInstance(const std::string& plantName) {
    if (!isPlantType(plantName)) {
        return nullptr;
    }

    std::unique_ptr<Plant> prototype;
    if (plantRegistry != nullptr) {
        if (Plant* clone = plantRegistry->createPlant(plantName, "")) {
            prototype.reset(clone);
        }
    }

    std::unique_ptr<PlantInstance> instance = std::make_unique<PlantInstance>(prototype.get(), "");
    PlantInstance* rawInstance = instance.get();
    if (prototype) {
        if (WaterStrategy* water = prototype->getDefaultWaterStrat()) {
            rawInstance->setWaterStrategy(water);
        }
        if (FertilizeStrategy* fertiliser = prototype->getDefaultFertStrat()) {
            rawInstance->setFertilizeStrategy(fertiliser);
        }
    }
    if (!prototype) {
        const std::string counterKey = plantCounterKey(plantName);
        const int counter = ++plantInstanceCounters[counterKey];
        const std::string baseName = plantCounterKey(plantName);
        rawInstance->rename(baseName + std::to_string(counter));
    }

    registerPlant(instance.release(), true);
    if (prototype) {
        prototypeOwners.emplace(rawInstance, std::move(prototype));
    }
    return rawInstance;
}

void Inventory::registerPlant(PlantInstance* plant, bool takeOwnership) {
    if (plant == nullptr) {
        return;
    }

    if (takeOwnership) {
        if (ownedPlantSet.insert(plant).second) {
            std::unique_ptr<PlantInstance> owned(plant);
            if (greenhouseRoot != nullptr) {
                greenhouseRoot->add(std::move(owned));
            } else {
                pendingPlants.push_back(std::move(owned));
            }
        }
    }

    greenhousePlants.insert(plant);
}

void Inventory::unregisterPlant(PlantInstance* plant) {
    if (plant == nullptr) {
        return;
    }

    greenhousePlants.erase(plant);

    if (ownedPlantSet.erase(plant) > 0U) {
        prototypeOwners.erase(plant);

        if (greenhouseRoot != nullptr) {
            greenhouseRoot->releasePlant(plant);
        } else {
            auto it = std::find_if(pendingPlants.begin(), pendingPlants.end(),
                [plant](const std::unique_ptr<PlantInstance>& candidate) {
                    return candidate.get() == plant;
                });
            if (it != pendingPlants.end()) {
                pendingPlants.erase(it);
            }
        }
        return;
    }

    if (greenhouseRoot != nullptr) {
        greenhouseRoot->remove(plant);
    }
}

void Inventory::releaseManagedPlants() {
    if (greenhouseRoot != nullptr) {
        for (PlantInstance* plant : ownedPlantSet) {
            greenhouseRoot->releasePlant(plant);
        }
    }
    pendingPlants.clear();
    greenhousePlants.clear();
    ownedPlantSet.clear();
    prototypeOwners.clear();
}
