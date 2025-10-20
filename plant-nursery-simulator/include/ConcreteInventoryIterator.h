#ifndef CONCRETE_INVENTORY_ITERATOR_H
#define CONCRETE_INVENTORY_ITERATOR_H

#include "InventoryIterator.h"

// Forward declaration
class Inventory;
class PlantInstance;

/**
 * @file ConcreteInventoryIterator.h
 * @brief The 'ConcreteIterator' for the Inventory.
 */
class ConcreteInventoryIterator : public InventoryIterator {
public:
    ConcreteInventoryIterator(Inventory* inv);

    PlantInstance* first() override;
    PlantInstance* next() override;
    bool hasNext() const override;
    PlantInstance* currentItem() const override;

private:
    Inventory* inventory; ///< Pointer to the Aggregate it traverses.
    int current; ///< The current position.
};

#endif // CONCRETE_INVENTORY_ITERATOR_H