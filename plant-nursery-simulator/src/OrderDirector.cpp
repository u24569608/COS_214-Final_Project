/**
 * @file OrderDirector.cpp
 * @brief Implements the OrderDirector behaviour defined in the corresponding header.
 */

#include "../include/OrderDirector.h"
#include "../include/CustomOrderBuilder.h" // Needs to create a concrete builder
#include "../include/Order.h"              // For getOrder()
#include "../include/StockItem.h"          
#include "../include/PlantInstance.h"      
#include <iostream>

OrderDirector::OrderDirector() : builder(nullptr) {
    // Constructor
}

/**
 * @brief Destructor.
 * Manages the memory of the builder it creates.
 */
OrderDirector::~OrderDirector() {
    delete builder;
}

/**
 * @brief (As per our assumption) Creates a new builder.
 */
void OrderDirector::setBuilder() {
    delete builder; // Delete old one if it exists
    builder = new CustomOrderBuilder();
}

/**
 * @brief (As per our assumption) Gets the order from the owned builder.
 */
Order* OrderDirector::getOrder() {
    if (builder) {
        return builder->getOrder();
    }
    return nullptr;
}

/**
 * @brief Builds a preset "Gift Basket".
 */
void OrderDirector::buildGiftBasket() {
    if (!builder) {
        std::cerr << "Director: No builder set. Call setBuilder() first." << std::endl;
        return;
    }
    
    builder->createNewOrder();
    
    // Create dummy items ON THE STACK
    StockItem pot("Small Pot", 5, nullptr);
    StockItem rose("Red Rose", 10, nullptr);
    StockItem ribbon("Ribbon", 2, nullptr);

    // Pass their addresses. The builder will make copies.
    builder->addItem(&pot);
    builder->addItem(&rose);
    builder->addItem(&ribbon);
}

/**
 * @brief Builds a preset "Beginner Set".
 */
void OrderDirector::buildBeginnerSet() {
    if (!builder) {
        std::cerr << "Director: No builder set. Call setBuilder() first." << std::endl;
        return;
    }

    builder->createNewOrder();

    StockItem spade("Hand Trowel", 12, nullptr);
    StockItem soil("Potting Soil (5L)", 7, nullptr);
    StockItem pot("Terracotta Pot", 5, nullptr);

    builder->addItem(&spade);
    builder->addItem(&soil);
    builder->addItem(&pot);
}

void OrderDirector::buildFullGardenerKit() {
    if (!builder) {
        std::cerr << "Director: No builder set. Call setBuilder() first." << std::endl;
        return;
    }

    builder->createNewOrder();
    
    buildBeginnerSet(); // Build on top of the beginner set

    StockItem gloves("Gardening Gloves", 15, nullptr);
    StockItem shears("Pruning Shears", 20, nullptr);
    
    builder->addItem(&gloves);
    builder->addItem(&shears);
}