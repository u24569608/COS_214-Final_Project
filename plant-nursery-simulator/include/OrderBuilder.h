#ifndef ORDER_BUILDER_H
#define ORDER_BUILDER_H

#include <string>
#include <memory> // For unique_ptr

// Forward declaration
class Order;

/**
 * @file OrderBuilder.h
 * @brief The abstract 'Builder' interface.
 */
class OrderBuilder {
public:
    virtual ~OrderBuilder();
    
    Order* getOrder();
    void createNewOrder();

    virtual void addPlant(std::string name, double price) = 0;
    virtual void addPot(std::string type, double price) = 0;
    virtual void addGiftWrap(double price) = 0;
    virtual void addSoil(std::string type, double price) = 0; // Creative

protected:
    std::unique_ptr<Order> order;
};

#endif // ORDER_BUILDER_H