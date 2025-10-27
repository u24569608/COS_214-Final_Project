#include "../include/CSVAdapter.h"
#include "../include/CSVReaderWriter.h"
#include "../include/Inventory.h"
#include "../include/StockItem.h" // Needed to create items
#include "../include/InventoryIterator.h" 
#include "../include/PlantPrototypeRegistry.h"
#include <iostream>
#include <memory>

CSVAdapter::CSVAdapter()
    : csvReader(std::make_unique<CSVReaderWriter>()) {
}

/**
 * @brief Loads inventory from a CSV file and recreates greenhouse-backed plant instances.
 * @note Stock names with registered prototypes are promoted to plant stock so greenhouse beds stay in sync.
 */
void CSVAdapter::loadInventory(std::string filePath, Inventory* inventory) {
    if (!inventory) {
        std::cerr << "[CSVAdapter] Error: Inventory pointer is null." << std::endl;
        return;
    }

    std::vector<std::pair<std::string, double>> data = csvReader->readCsv(filePath);

    for (const auto& pair : data) {
        bool treatAsPlant = inventory->isPlantType(pair.first);
        PlantPrototypeRegistry* registry = inventory->getPlantRegistry();
        if (!treatAsPlant && registry != nullptr && registry->hasPrototype(pair.first)) {
            inventory->registerPlantType(pair.first);
            treatAsPlant = true;
        }
        PlantInstance* plant = treatAsPlant ? inventory->createPlantInstance(pair.first) : nullptr;
        inventory->additem(std::make_unique<StockItem>(pair.first, pair.second, plant));
    }
     std::cout << "[CSVAdapter] Loaded data from " << filePath << std::endl;
}

/**
 * @brief Saves inventory to a CSV file using the CSVReaderWriter.
 */
void CSVAdapter::saveInventory(std::string filePath, Inventory* inventory) {
    if (!inventory) {
        std::cerr << "[CSVAdapter] Error: Inventory pointer is null." << std::endl;
        return;
    }

    // --- Using the iterator method (if Inventory cannot be changed) ---
    std::vector<StockItem*> itemsToSave;
    InventoryIterator* iter = inventory->createIterator();
    for(StockItem* item = iter->first(); iter->hasNext(); item = iter->next()) {
        itemsToSave.push_back(item);
    }
    delete iter; // Clean up iterator

    if (csvReader->writeDataToCSV(filePath, itemsToSave)) {
        std::cout << "[CSVAdapter] Saved inventory to " << filePath << std::endl;
    } else {
        std::cerr << "[CSVAdapter] Error: Failed to save inventory to " << filePath << std::endl;
    }
}
