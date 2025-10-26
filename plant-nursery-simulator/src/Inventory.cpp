#include "../include/Inventory.h"
#include "../include/ConcreteInventoryIterator.h" // For createIterator()
#include "../include/StockItem.h"                 // For item definitions
#include <algorithm>                   // For std::find_if, std::remove_if

Inventory::Inventory() {
    // Constructor
}

// Destructor must clean up all the dynamically allocated StockItems
Inventory::~Inventory() {
    for (StockItem* item : items) {
        delete item;
    }
    items.clear();
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
        items.erase(it);               // Erase the pointer from the vector
        delete itemToDelete;           // Delete the object from memory
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

// --- Stubbed Adapter Methods ---
// These are for a different pattern.I'll leave them empty for bulelani to implament.
// they are here so the program can compile.

void Inventory::loadFromFile(FileAdapter* adapter, std::string filePath) {
    // Logic for the Adapter pattern will go here later
}

void Inventory::saveToFile(FileAdapter* adapter, std::string filePath) {
    // Logic for the Adapter pattern will go here later
}