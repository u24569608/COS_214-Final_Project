#ifndef INVENTORY_COLLECTION_H
#define INVENTORY_COLLECTION_H

// Forward declaration
class InventoryIterator;

/**
 * @file InventoryCollection.h
 * @brief The 'Aggregate' interface. (FR14)
 */
class InventoryCollection {
public:
    virtual ~InventoryCollection();
    /**
     * @brief Creates an iterator to traverse the collection.
     * @return InventoryIterator* A pointer to a new iterator.
     */
    virtual InventoryIterator* createIterator() = 0;
};

#endif // INVENTORY_COLLECTION_H