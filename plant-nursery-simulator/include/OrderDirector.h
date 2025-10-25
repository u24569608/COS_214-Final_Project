#ifndef ORDER_DIRECTOR_H
#define ORDER_DIRECTOR_H

// Forward declaration
class OrderBuilder;
class Order; // <-- Forward declare Order

/**
 * @file OrderDirector.h
 * @brief The 'Director' for the Builder pattern.
 */
class OrderDirector {
public:
    OrderDirector();
    ~OrderDirector(); // <-- ADDED: To prevent memory leaks
    
    void setBuilder();
    Order* getOrder(); // <-- ADDED: To retrieve the final product
    
    void buildGiftBasket();
    void buildBeginnerSet();
    void buildFullGardenerKit(); // Creative

private:
    OrderBuilder* builder; ///< The builder it directs.
};

#endif // ORDER_DIRECTOR_H