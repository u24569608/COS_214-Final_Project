#include "../include/ConcreteInventoryIterator.h"
#include "Inventory.h" // Needs the full definition of Inventory
#include "StockItem.h"

/**
 * @brief Constructor.
 * @param inv The Inventory (Aggregate) to iterate over.
 */
ConcreteInventoryIterator::ConcreteInventoryIterator(Inventory* inv)
    : inventory(inv), currentIndex(0) {
    // 'inventory' now points to the Inventory object
    // 'currentIndex' starts at the beginning
}

/**
 * @brief Resets position to the start and returns the first item.
 */
StockItem* ConcreteInventoryIterator::first() {
    currentIndex = 0;
    return currentItem();
}

/**
 * @brief Moves to the next item and returns it.
 */
StockItem* ConcreteInventoryIterator::next() {
    // Only increment if there's a next item to move to
    if (hasNext()) {
        currentIndex++;
    }
    return currentItem();
}

/**
 * @brief Checks if there are more items to iterate over.
 */
bool ConcreteInventoryIterator::hasNext() const {
    // We can access 'items' directly because we are a 'friend'
    // [see: Inventory.h]
    return currentIndex < inventory->items.size();
}

/**
 * @brief Gets the item at the current position.
 */
StockItem* ConcreteInventoryIterator::currentItem() const {
    if (hasNext()) {
        // We can access 'items' directly
        return inventory->items[currentIndex];
    }
    return nullptr; // We are at the end of the collection
}

/**
 * @brief Resets the iterator's position to the beginning.
 */
void ConcreteInventoryIterator::reset() {
    currentIndex = 0;
}