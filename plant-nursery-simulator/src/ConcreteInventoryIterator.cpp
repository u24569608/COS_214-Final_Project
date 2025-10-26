#include "../include/ConcreteInventoryIterator.h"
#include "../include/Inventory.h" // Needs the full definition of Inventory
#include "../include/StockItem.h"
#include <vector> // Needed for size_t

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
    // We use hasNext() which already does the check
    if (hasNext()) {
         currentIndex++;
         // Return the item *after* incrementing
         return currentItem();
    }
    // If there is no next, return nullptr without incrementing
    return nullptr;
}

/**
 * @brief Checks if there are more items to iterate over.
 */
bool ConcreteInventoryIterator::hasNext() const {
    // Cast currentIndex to size_t (the type of vector::size())
    // to fix the signed/unsigned comparison warning.
    // This is safe because currentIndex should never be negative here.
    return static_cast<size_t>(currentIndex) < inventory->items.size();
}

/**
 * @brief Gets the item at the current position.
 */
StockItem* ConcreteInventoryIterator::currentItem() const {
    // Check bounds *before* accessing the vector element
    if (static_cast<size_t>(currentIndex) >= 0 && static_cast<size_t>(currentIndex) < inventory->items.size()) {
        return inventory->items[currentIndex];
    }
    return nullptr; // We are at the end or index is invalid
}

/**
 * @brief Resets the iterator's position to the beginning.
 */
void ConcreteInventoryIterator::reset() {
    currentIndex = 0;
}
