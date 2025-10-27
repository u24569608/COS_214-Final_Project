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

Inventory::Inventory()
    : greenhouseRoot(nullptr),
      plantRegistry(nullptr) {
}

Inventory::~Inventory() {
    for (StockItem* item : items) {
        delete item;
    }
    items.clear();
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

void Inventory::additem(StockItem* item) {
    if (item != nullptr) {
        items.push_back(item);
        registerPlant(item->getplant(), false);
    }
}

void Inventory::removeItem(std::string name) {
    // 1. Find the first item that matches the name
    auto it = std::find_if(items.begin(), items.end(), 
        [&name](StockItem* item) {
            return item->getname() == name;
        });

    // 2. If we found it, delete and erase
    if (it != items.end()) {
        StockItem* itemToDelete = *it; // Get the pointer
        PlantInstance* plant = itemToDelete->getplant();
        items.erase(it);               // Erase the pointer from the vector
        delete itemToDelete;           // Delete the object from memory
        unregisterPlant(plant);
    }
}

int Inventory::getStockCount(std::string plantType) const {
    // Use std::count_if from <algorithm> with a lambda
    return std::count_if(items.begin(), items.end(), 
        [&plantType](StockItem* item) {
            // This relies on the corrected StockItem.h
            return item->getname() == plantType;
        });
}

StockItem* Inventory::findItem(std::string name) {
    // Use std::find_if from <algorithm> with a lambda
    auto it = std::find_if(items.begin(), items.end(), 
        [&name](StockItem* item) {
            // This relies on the corrected StockItem.h
            return item->getname() == name;
        });

    if (it != items.end()) {
        return *it; // Return the pointer to the found item
    }
    return nullptr; // Not found
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
    for (StockItem* item : items) {
        delete item;
    }
    items.clear();
    releaseManagedPlants();

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

    PlantInstance* instance = new PlantInstance(prototype.get(), "");
    if (!prototype) {
        const std::string counterKey = plantName.empty() ? "Plant" : plantName;
        const int counter = ++plantInstanceCounters[counterKey];
        const std::string baseName = plantName.empty() ? "Plant" : plantName;
        instance->rename(baseName + std::to_string(counter));
    }
    registerPlant(instance, true);
    if (prototype) {
        prototypeOwners.emplace(instance, std::move(prototype));
    }
    return instance;
}

void Inventory::registerPlant(PlantInstance* plant, bool takeOwnership) {
    if (plant == nullptr) {
        return;
    }

    if (greenhouseRoot != nullptr) {
        const bool inserted = greenhousePlants.insert(plant).second;
        if (inserted) {
            greenhouseRoot->add(plant);
        }
    } else {
        greenhousePlants.insert(plant);
    }

    if (takeOwnership) {
        const bool inserted = ownedPlantSet.insert(plant).second;
        if (inserted) {
            ownedPlants.push_back(plant);
        }
    }
}

void Inventory::unregisterPlant(PlantInstance* plant) {
    if (plant == nullptr) {
        return;
    }

    if (greenhousePlants.erase(plant) > 0U && greenhouseRoot != nullptr) {
        greenhouseRoot->remove(plant);
    }

    if (ownedPlantSet.erase(plant) > 0U) {
        auto it = std::remove(ownedPlants.begin(), ownedPlants.end(), plant);
        if (it != ownedPlants.end()) {
            ownedPlants.erase(it, ownedPlants.end());
        }
        prototypeOwners.erase(plant);
        delete plant;
    }
}

void Inventory::releaseManagedPlants() {
    if (greenhouseRoot != nullptr) {
        for (PlantInstance* plant : greenhousePlants) {
            greenhouseRoot->remove(plant);
        }
    }
    greenhousePlants.clear();

    for (PlantInstance* plant : ownedPlants) {
        delete plant;
    }
    ownedPlants.clear();
    ownedPlantSet.clear();
    prototypeOwners.clear();
}
