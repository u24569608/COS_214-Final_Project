/**
 * @file CustomOrderBuilder.cpp
 * @brief Implements the CustomOrderBuilder behaviour defined in the corresponding header.
 */

#include "../include/CustomOrderBuilder.h"
#include "../include/Order.h"
#include "../include/StockItem.h"

/**
 * @brief Constructor. Immediately creates a new order.
 */
CustomOrderBuilder::CustomOrderBuilder() {
    createNewOrder();
}

/**
 * @brief Adds an item to the order.
 * This is the fix for the header mismatch.
 * @param item A pointer to the item (from Inventory/Director).
 */
void CustomOrderBuilder::addItem(StockItem* item) {
    if (item == nullptr) {
        return; // Safety check
    }
    
    // We dereference the pointer (*item) to create a StockItem object.
    // The Order's addItem function then makes a *copy* of it.
    order->addItem(*item);
}