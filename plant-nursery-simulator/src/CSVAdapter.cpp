#include "../include/CSVAdapter.h"
#include "../include/CSVReaderWriter.h"
#include "../include/Inventory.h"
#include "../include/StockItem.h" // Needed to create items
#include "../include/InventoryIterator.h" 
#include <iostream>

CSVAdapter::CSVAdapter() {
    csvReader = new CSVReaderWriter();
}

CSVAdapter::~CSVAdapter() {
    delete csvReader;
}

/**
 * @brief Loads inventory from a CSV file using the CSVReaderWriter.
 */
void CSVAdapter::loadInventory(std::string filePath, Inventory* inventory) {
    if (!inventory) {
        std::cerr << "[CSVAdapter] Error: Inventory pointer is null." << std::endl;
        return;
    }

    std::vector<std::pair<std::string, double>> data = csvReader->readCsv(filePath);

    for (const auto& pair : data) {
        // Create a new StockItem for each valid pair and add it
        inventory->additem(new StockItem(pair.first, pair.second, nullptr));
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
