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
    virtual ~InventoryIterator();
    virtual StockItem* first() = 0;
    virtual StockItem* next() = 0;
    virtual bool hasNext() const = 0;
    virtual StockItem* currentItem() const = 0;
    virtual void reset();
};

#endif // INVENTORY_ITERATOR_H
