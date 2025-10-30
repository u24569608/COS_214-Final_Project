/**
 * @file OrderBuilder.cpp
 * @brief Implements the OrderBuilder behaviour defined in the corresponding header.
 */

#include "../include/OrderBuilder.h"
#include "../include/Order.h"

// Virtual destructor definition
OrderBuilder::~OrderBuilder() {
    // Nothing to do, std::unique_ptr handles memory
}

/**
 * @brief Creates a new, empty Order product.
 * This is called by the ConcreteBuilder's constructor.
 */
void OrderBuilder::createNewOrder() {
    // std::make_unique is the C++17 way
    order = std::make_unique<Order>();
}

/**
 * @brief Hands off ownership of the final Order to the client.
 * @return Order* A raw pointer to the heap-allocated Order.
 */
Order* OrderBuilder::getOrder() {
    // .release() gives up ownership and returns the raw pointer.
    // The caller is now responsible for deleting this Order.
    return order.release();
}