/**
 * @file TXTAdapter.cpp
 * @brief Implements the TXTAdapter behaviour defined in the corresponding header.
 */

#include "../include/TXTAdapter.h"
#include "../include/TXTReaderWriter.h"
#include "../include/Inventory.h"
#include "../include/StockItem.h" // Needed to create items
#include "../include/InventoryIterator.h" 
#include "../include/PlantPrototypeRegistry.h"
#include "../include/PlantInstance.h"
#include "../include/PlantState.h"
#include "../include/Plant.h"
#include "../include/SeedState.h"
#include "../include/GrowingState.h"
#include "../include/MatureState.h"
#include "../include/WitheringState.h"
#include "../include/DeadState.h"
#include <sstream>
#include <iostream>
#include <memory>

TXTAdapter::TXTAdapter()
    : txtReader(std::make_unique<TXTReaderWriter>()) {
}

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
        std::cerr << "[TXTAdapter] Warning: Invalid price '" << raw << "' on line "
                  << lineNumber << " of " << filePath << ". Defaulting to 0.\n";
        return 0.0;
    }
}

class ImportedPlantPrototype : public Plant {
public:
	explicit ImportedPlantPrototype(const std::string& plantName) {
		setName(plantName);
		setType("Imported");
	}

	ImportedPlantPrototype(const ImportedPlantPrototype& other) : Plant() {
		setName(other.getName());
		setType(other.getType());
		setDefaultWaterStrat(other.getDefaultWaterStrat());
		setDefaultFertStrat(other.getDefaultFertStrat());
	}

	Plant* clone() const override {
		return new ImportedPlantPrototype(*this);
	}
};

void ensurePrototypeExists(PlantPrototypeRegistry* registry, const std::string& plantName) {
	if (!registry || plantName.empty() || registry->hasPrototype(plantName)) {
		return;
	}

	registry->addPrototype(plantName, std::make_unique<ImportedPlantPrototype>(plantName));
}
} // namespace

/**
 * @brief Loads inventory from a TXT file and rebuilds greenhouse-linked plant instances.
 * @note Expected file format per line:
 *       Item,<name>,<price>
 *       Plant,<name>,<price>,<state>
 */
void TXTAdapter::loadInventory(std::string filePath, Inventory* inventory) {
    if (!inventory) {
        std::cerr << "[TXTAdapter] Error: Inventory pointer is null." << std::endl;
        return;
    }

    std::vector<std::string> lines = txtReader->readDataFromTxt(filePath);

    for (size_t i = 0; i < lines.size(); ++i) {
        std::stringstream ss(lines[i]);
        std::string token;
        std::vector<std::string> parts;
        while (std::getline(ss, token, ',')) {
            if (!token.empty()) {
                // trim whitespace
                const auto first = token.find_first_not_of(" \t");
                const auto last = token.find_last_not_of(" \t");
                parts.push_back(first == std::string::npos ? std::string() : token.substr(first, last - first + 1));
            } else {
                parts.emplace_back();
            }
        }

        if (parts.empty()) {
            continue;
        }

        const std::string& entryType = parts[0];
        if (entryType == "Item") {
            if (parts.size() < 3U) {
                std::cerr << "[TXTAdapter] Warning: Malformed item row on line " << (i + 1)
                          << ": '" << lines[i] << "'" << std::endl;
                continue;
            }
            const std::string& name = parts[1];
            const double price = parsePrice(parts[2], i + 1, filePath);
            inventory->additem(std::make_unique<StockItem>(name, price, nullptr));
            continue;
        }

        if (entryType == "Plant") {
            if (parts.size() < 4U) {
                std::cerr << "[TXTAdapter] Warning: Malformed plant row on line " << (i + 1)
                          << ": '" << lines[i] << "'" << std::endl;
                continue;
            }
            const std::string& name = parts[1];
            const double price = parsePrice(parts[2], i + 1, filePath);
            const std::string& stateLabel = parts[3];

            PlantPrototypeRegistry* registry = inventory->getPlantRegistry();
            if (registry != nullptr) {
                ensurePrototypeExists(registry, name);
            }

            const bool treatAsPlant = registry != nullptr && registry->hasPrototype(name);
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

        std::cerr << "[TXTAdapter] Warning: Unknown entry type on line " << (i + 1)
                  << ": '" << entryType << "'" << std::endl;
    }
     std::cout << "[TXTAdapter] Loaded data from " << filePath << std::endl;
}

/**
 * @brief Saves inventory to a TXT file using the TXTReaderWriter.
 * @note Emits entries in the same Item/Plant format consumed by loadInventory.
 */
void TXTAdapter::saveInventory(std::string filePath, Inventory* inventory) {
     if (!inventory) {
        std::cerr << "[TXTAdapter] Error: Inventory pointer is null." << std::endl;
        return;
    }

    std::vector<StockItem*> itemsToSave;
    std::unique_ptr<InventoryIterator> iter(inventory->createIterator());
    for (StockItem* item = iter ? iter->first() : nullptr; item != nullptr; item = iter->next()) {
        itemsToSave.push_back(item);
    }

    if (txtReader->writeDataToTxt(filePath, itemsToSave)) {
        std::cout << "[TXTAdapter] Saved inventory to " << filePath << std::endl;
    } else {
        std::cerr << "[TXTAdapter] Error: Failed to save inventory to " << filePath << std::endl;
    }
}
