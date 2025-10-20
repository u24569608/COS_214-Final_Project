#ifndef INVENTORY_ITERATOR_H
#define INVENTORY_ITERATOR_H

// Forward declaration
class PlantInstance;

/**
 * @file InventoryIterator.h
 * @brief The 'Iterator' interface. (FR15)
 */
class InventoryIterator {
public:
    virtual ~InventoryIterator();
    virtual PlantInstance* first() = 0;
    virtual PlantInstance* next() = 0;
    virtual bool hasNext() const = 0;
    virtual PlantInstance* currentItem() const = 0;
};

#endif // INVENTORY_ITERATOR_H