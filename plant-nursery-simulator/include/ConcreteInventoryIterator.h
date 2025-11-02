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
    /**
     * @brief Binds the iterator to an inventory aggregate for traversal.
     * @param inv Inventory instance that owns the stock entries to iterate.
     */
    ConcreteInventoryIterator(Inventory* inv);

    /** @copydoc InventoryIterator::first */
    StockItem* first() override;
    /** @copydoc InventoryIterator::next */
    StockItem* next() override;
    /** @copydoc InventoryIterator::hasNext */
    bool hasNext() const override;
    /** @copydoc InventoryIterator::currentItem */
    StockItem* currentItem() const override;
    /** @copydoc InventoryIterator::reset */
    void reset() override;

private:
    Inventory* inventory; ///< Pointer to the Aggregate it traverses.
    mutable std::vector<StockItem*> traversalOrder; ///< Cached traversal sequence.
    mutable std::size_t currentIndex; ///< The current position within the traversal.
    mutable bool traversalDirty; ///< Marks when the cached traversal needs rebuilding.

    /**
     * @brief Recomputes the cached traversal order from the associated inventory.
     */
    void rebuildTraversal() const;
};

#endif // CONCRETE_INVENTORY_ITERATOR_H
