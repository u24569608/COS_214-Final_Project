#ifndef CONCRETE_INVENTORY_ITERATOR_H
#define CONCRETE_INVENTORY_ITERATOR_H

#include "InventoryIterator.h"
#include <vector>

// Forward declaration
class Inventory;
class StockItem;
class PlantInstance;

/**
 * @file ConcreteInventoryIterator.h
 * @brief The 'ConcreteIterator' for the Inventory.
 * @details Prioritises market-ready plants sourced from the greenhouse composite before
 *          iterating remaining stock entries.
 */
class ConcreteInventoryIterator : public InventoryIterator {
public:
    ConcreteInventoryIterator(Inventory* inv);

    StockItem* first() override;
    StockItem* next() override;
    bool hasNext() const override;
    StockItem* currentItem() const override;
    void reset() override;

private:
    Inventory* inventory; ///< Pointer to the Aggregate it traverses.
    mutable std::vector<StockItem*> traversalOrder; ///< Cached traversal sequence.
    mutable std::size_t currentIndex; ///< The current position within the traversal.
    mutable bool traversalDirty; ///< Marks when the cached traversal needs rebuilding.

    void rebuildTraversal() const;
};

#endif // CONCRETE_INVENTORY_ITERATOR_H
