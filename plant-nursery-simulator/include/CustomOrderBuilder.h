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
    CustomOrderBuilder();
    
    void addItem(StockItem* item);
};

#endif // CUSTOM_ORDER_BUILDER_H