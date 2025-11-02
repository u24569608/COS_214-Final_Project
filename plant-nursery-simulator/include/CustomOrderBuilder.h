#ifndef CUSTOM_ORDER_BUILDER_H
#define CUSTOM_ORDER_BUILDER_H

#include "OrderBuilder.h"
#include <string>

/**
 * @file CustomOrderBuilder.h
 * @brief The 'ConcreteBuilder' implementation.
 */
class CustomOrderBuilder : public OrderBuilder {
public:
    /**
     * @brief Instantiates a builder that accumulates bespoke order line items.
     */
    CustomOrderBuilder();

    /**
     * @brief Appends a stock item to the order currently being constructed.
     * @param item Pointer to the stock item being requested.
     */
    void addItem(StockItem* item);
};

#endif // CUSTOM_ORDER_BUILDER_H
