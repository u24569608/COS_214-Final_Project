#ifndef CONCRETE_INVENTORY_ITERATOR_H
#define CONCRETE_INVENTORY_ITERATOR_H

#include "InventoryIterator.h"

// Forward declaration
class Inventory;
class StockItem;

/**
 * @file ConcreteInventoryIterator.h
 * @brief The 'ConcreteIterator' for the Inventory.
 */
class ConcreteInventoryIterator : public InventoryIterator {
public:
    ConcreteInventoryIterator(Inventory* inv);

    StockItem* first() override;
    StockItem* next() override;
    bool hasNext() const override;
    StockItem* currentItem() const override;
    void reset();

private:
    Inventory* inventory; ///< Pointer to the Aggregate it traverses.
    int currentIndex; ///< The current position.
};

#endif // CONCRETE_INVENTORY_ITERATOR_H