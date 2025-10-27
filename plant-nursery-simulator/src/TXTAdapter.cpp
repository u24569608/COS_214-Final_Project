#include "../include/TXTAdapter.h"
#include "../include/TXTReaderWriter.h"
#include "../include/Inventory.h"
#include "../include/StockItem.h" // Needed to create items
#include "../include/InventoryIterator.h" 
#include "../include/PlantPrototypeRegistry.h"
#include <sstream>
#include <iostream>
#include <memory>

TXTAdapter::TXTAdapter()
    : txtReader(std::make_unique<TXTReaderWriter>()) {
}

/**
 * @brief Loads inventory from a TXT file and rebuilds greenhouse-linked plant instances.
 * @note Stock names with registered prototypes are promoted to plant stock so greenhouse beds stay in sync.
 */
void TXTAdapter::loadInventory(std::string filePath, Inventory* inventory) {
    if (!inventory) {
        std::cerr << "[TXTAdapter] Error: Inventory pointer is null." << std::endl;
        return;
    }

    std::vector<std::string> lines = txtReader->readDataFromTxt(filePath);

    for (size_t i = 0; i < lines.size(); ++i) {
        std::stringstream ss(lines[i]);
        std::string name;
        double price;

        // Try to parse "ItemName Price"
        if (ss >> name >> price) {
            // Check if there's extra data on the line
            std::string remaining;
            if (ss >> remaining) {
                 std::cerr << "[TXTAdapter] Warning: Extra data on line " << (i + 1)
                          << " in file " << filePath << ". Ignoring extra data: " << remaining << std::endl;
            }
            // Create a new StockItem and add it
            bool treatAsPlant = inventory->isPlantType(name);
            PlantPrototypeRegistry* registry = inventory->getPlantRegistry();
            if (!treatAsPlant && registry != nullptr && registry->hasPrototype(name)) {
                inventory->registerPlantType(name);
                treatAsPlant = true;
            }
            PlantInstance* plant = treatAsPlant ? inventory->createPlantInstance(name) : nullptr;
            inventory->additem(std::make_unique<StockItem>(name, price, plant));
            
        } else if (!lines[i].empty()) {
             std::cerr << "[TXTAdapter] Warning: Malformed line " << (i + 1)
                      << " in file " << filePath << ". Expected 'Name Price'. Skipping row: " << lines[i] << std::endl;
        }
    }
     std::cout << "[TXTAdapter] Loaded data from " << filePath << std::endl;
}

/**
 * @brief Saves inventory to a TXT file using the TXTReaderWriter.
 */
void TXTAdapter::saveInventory(std::string filePath, Inventory* inventory) {
     if (!inventory) {
        std::cerr << "[TXTAdapter] Error: Inventory pointer is null." << std::endl;
        return;
    }

    std::vector<StockItem*> itemsToSave;
    InventoryIterator* iter = inventory->createIterator();
    for(StockItem* item = iter->first(); iter->hasNext(); item = iter->next()) {
        itemsToSave.push_back(item);
    }
    delete iter; // Clean up iterator

    if (txtReader->writeDataToTxt(filePath, itemsToSave)) {
        std::cout << "[TXTAdapter] Saved inventory to " << filePath << std::endl;
    } else {
        std::cerr << "[TXTAdapter] Error: Failed to save inventory to " << filePath << std::endl;
    }
}
