#ifndef INVENTORY_ITERATOR_H
#define INVENTORY_ITERATOR_H

// Forward declaration
class StockItem;

/**
 * @file InventoryIterator.h
 * @brief The 'Iterator' interface. (FR15)
 */
class InventoryIterator {
public:
    /**
     * @brief Ensures cleanup when deleting via interface pointer.
     */
    virtual ~InventoryIterator();

    /**
     * @brief Positions the iterator at the first stock item.
     * @return Pointer to the first entry, or nullptr if empty.
     */
    virtual StockItem* first() = 0;

    /**
     * @brief Advances to the next stock entry.
     * @return Pointer to the next entry, or nullptr when the traversal ends.
     */
    virtual StockItem* next() = 0;

    /**
     * @brief Reports whether there is another stock entry available.
     * @return True if iteration can continue.
     */
    virtual bool hasNext() const = 0;

    /**
     * @brief Retrieves the stock item at the current iterator position.
     * @return Pointer to the current entry, or nullptr if invalid.
     */
    virtual StockItem* currentItem() const = 0;

    /**
     * @brief Resets the iterator to its initial position.
     */
    virtual void reset();
};

#endif // INVENTORY_ITERATOR_H
