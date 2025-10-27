#include "../include/ConcreteInventoryIterator.h"
#include "../include/Inventory.h"
#include "../include/StockItem.h"
#include "../include/GreenhouseBed.h"
#include "../include/GreenhouseIterator.h"
#include "../include/PlantInstance.h"
#include <unordered_set>

/**
 * @brief Constructor.
 * @param inv The Inventory (Aggregate) to iterate over.
 */
ConcreteInventoryIterator::ConcreteInventoryIterator(Inventory* inv)
    : inventory(inv),
      traversalOrder(),
      currentIndex(0U),
      traversalDirty(true) {
}

StockItem* ConcreteInventoryIterator::first() {
    rebuildTraversal();
    if (traversalOrder.empty()) {
        return nullptr;
    }
    currentIndex = 0U;
    return traversalOrder[currentIndex];
}

StockItem* ConcreteInventoryIterator::next() {
    rebuildTraversal();
    if (traversalOrder.empty()) {
        return nullptr;
    }
    if (currentIndex + 1U < traversalOrder.size()) {
        ++currentIndex;
        return traversalOrder[currentIndex];
    }
    currentIndex = traversalOrder.size();
    return nullptr;
}

bool ConcreteInventoryIterator::hasNext() const {
    rebuildTraversal();
    return !traversalOrder.empty() && currentIndex < traversalOrder.size();
}

StockItem* ConcreteInventoryIterator::currentItem() const {
    rebuildTraversal();
    if (traversalOrder.empty() || currentIndex >= traversalOrder.size()) {
        return nullptr;
    }
    return traversalOrder[currentIndex];
}

void ConcreteInventoryIterator::reset() {
    currentIndex = 0U;
    traversalDirty = true;
}

void ConcreteInventoryIterator::rebuildTraversal() const {
    if (!traversalDirty) {
        return;
    }

    traversalOrder.clear();
    currentIndex = 0U;

    if (inventory == nullptr) {
        traversalDirty = false;
        return;
    }

    std::unordered_set<PlantInstance*> greenhousePlants;
    if (inventory->greenhouseRoot != nullptr) {
        if (auto iterator = inventory->greenhouseRoot->createIterator()) {
            for (PlantInstance* plant = iterator->first(); plant != nullptr; plant = iterator->next()) {
                greenhousePlants.insert(plant);
            }
        }
    }

    std::unordered_set<StockItem*> inserted;

    // Traverse plant-backed stock in greenhouse order, ensuring market readiness.
    if (inventory->greenhouseRoot != nullptr) {
        if (auto iterator = inventory->greenhouseRoot->createIterator()) {
            for (PlantInstance* plant = iterator->first(); plant != nullptr; plant = iterator->next()) {
                if (!plant->isAvailableForSale()) {
                    continue;
                }
                StockItem* matching = nullptr;
                for (const auto& stockPtr : inventory->items) {
                    if (stockPtr && stockPtr->getplant() == plant) {
                        matching = stockPtr.get();
                        break;
                    }
                }
                if (matching != nullptr) {
                    traversalOrder.push_back(matching);
                    inserted.insert(matching);
                }
            }
        }
    }

    // Append remaining stock that is either non-plant or plant-ready but not yet inserted.
    for (const auto& stockPtr : inventory->items) {
        if (!stockPtr) {
            continue;
        }
        StockItem* stock = stockPtr.get();
        if (inserted.count(stock) > 0U) {
            continue;
        }

        PlantInstance* plant = stock->getplant();
        if (plant != nullptr) {
            if (greenhousePlants.count(plant) == 0U) {
                continue;
            }
            if (!plant->isAvailableForSale()) {
                continue;
            }
        }

        traversalOrder.push_back(stock);
    }

    traversalDirty = false;
}
