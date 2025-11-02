/**
 * @file InventoryIterator.cpp
 * @brief Implements the InventoryIterator behaviour defined in the corresponding header.
 */

#include "../include/InventoryIterator.h"

// Define the virtual destructor
InventoryIterator::~InventoryIterator() {
    // Nothing to do in the base class
}

/**
 * @brief Non-virtual reset method (defined in the interface).
 * This works by calling the PURE VIRTUAL 'first()' method,
 * which will be implemented by the concrete class.
 */
void InventoryIterator::reset() {
    this->first();
}