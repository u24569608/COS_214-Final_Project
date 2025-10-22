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
    
    void addPlant(std::string name, double price) override;
    void addPot(std::string type, double price) override;
    void addGiftWrap(double price) override;
    void addSoil(std::string type, double price) override;
};

#endif // CUSTOM_ORDER_BUILDER_H