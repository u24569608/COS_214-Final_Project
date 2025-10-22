#ifndef ORDER_BUILDER_H
#define ORDER_BUILDER_H

#include <string>
#include <memory> // For unique_ptr

// Forward declaration
class Order;
class StockItem;

/**
 * @file OrderBuilder.h
 * @brief The abstract 'Builder' interface.
 */
class OrderBuilder {
public:
    virtual ~OrderBuilder();
    
    Order* getOrder();
    void createNewOrder();
    virtual void addItem(StockItem* item) = 0 ;

protected:
    std::unique_ptr<Order> order;
};

#endif // ORDER_BUILDER_H