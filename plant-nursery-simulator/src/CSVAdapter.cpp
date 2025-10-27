#include "../include/CSVAdapter.h"
#include "../include/CSVReaderWriter.h"
#include "../include/Inventory.h"
#include "../include/StockItem.h" // Needed to create items
#include "../include/InventoryIterator.h" 
#include "../include/PlantPrototypeRegistry.h"
#include "../include/PlantInstance.h"
#include "../include/PlantState.h"
#include "../include/SeedState.h"
#include "../include/GrowingState.h"
#include "../include/MatureState.h"
#include "../include/WitheringState.h"
#include "../include/DeadState.h"
#include <iostream>
#include <memory>

namespace {

std::unique_ptr<PlantState> makeStateFromLabel(const std::string& label) {
    if (label == "Seed") {
        return std::make_unique<SeedState>();
    }
    if (label == "Growing") {
        return std::make_unique<GrowingState>();
    }
    if (label == "Mature") {
        return std::make_unique<MatureState>();
    }
    if (label == "Withering") {
        return std::make_unique<WitheringState>();
    }
    if (label == "Dead") {
        return std::make_unique<DeadState>();
    }
    return nullptr;
}

double parsePrice(const std::string& raw, size_t lineNumber, const std::string& filePath) {
    try {
        return std::stod(raw);
    } catch (const std::exception&) {
        std::cerr << "[CSVAdapter] Warning: Invalid price '" << raw << "' on line "
                  << lineNumber << " of " << filePath << ". Defaulting to 0.\n";
        return 0.0;
    }
}

} // namespace

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

    const std::vector<std::vector<std::string>> rows = csvReader->readCsv(filePath);

    for (size_t i = 0; i < rows.size(); ++i) {
        const std::vector<std::string>& row = rows[i];
        if (row.empty()) {
            continue;
        }

        const std::string& entryType = row[0];
        if (entryType == "Item") {
            if (row.size() < 3U) {
                std::cerr << "[CSVAdapter] Warning: Malformed item row on line " << (i + 1)
                          << " in " << filePath << std::endl;
                continue;
            }
            const std::string& name = row[1];
            const double price = parsePrice(row[2], i + 1, filePath);
            inventory->additem(std::make_unique<StockItem>(name, price, nullptr));
            continue;
        }

        if (entryType == "Plant") {
            if (row.size() < 4U) {
                std::cerr << "[CSVAdapter] Warning: Malformed plant row on line " << (i + 1)
                          << " in " << filePath << std::endl;
                continue;
            }
            const std::string& name = row[1];
            const double price = parsePrice(row[2], i + 1, filePath);
            const std::string& stateLabel = row[3];

            bool treatAsPlant = true;
            PlantPrototypeRegistry* registry = inventory->getPlantRegistry();
            if (registry != nullptr && !registry->hasPrototype(name)) {
                treatAsPlant = false;
            }
            if (treatAsPlant) {
                inventory->registerPlantType(name);
            }
            PlantInstance* plant = treatAsPlant ? inventory->createPlantInstance(name) : nullptr;
            if (plant != nullptr) {
                if (std::unique_ptr<PlantState> desiredState = makeStateFromLabel(stateLabel)) {
                    plant->setState(std::move(desiredState));
                }
            }
            inventory->additem(std::make_unique<StockItem>(name, price, plant));
            continue;
        }

        std::cerr << "[CSVAdapter] Warning: Unknown entry type '" << entryType
                  << "' on line " << (i + 1) << " in " << filePath << std::endl;
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
    std::unique_ptr<InventoryIterator> iter(inventory->createIterator());
    for (StockItem* item = iter ? iter->first() : nullptr; item != nullptr; item = iter->next()) {
        itemsToSave.push_back(item);
    }

    if (csvReader->writeDataToCSV(filePath, itemsToSave)) {
        std::cout << "[CSVAdapter] Saved inventory to " << filePath << std::endl;
    } else {
        std::cerr << "[CSVAdapter] Error: Failed to save inventory to " << filePath << std::endl;
    }
}
