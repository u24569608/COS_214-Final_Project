#ifndef ORDER_DIRECTOR_H
#define ORDER_DIRECTOR_H

// Forward declaration
class OrderBuilder;

/**
 * @file OrderDirector.h
 * @brief The 'Director' for the Builder pattern.
 */
class OrderDirector {
public:
    OrderDirector();
    void setBuilder(OrderBuilder* b);

    void buildGiftBasket();
    void buildBeginnerSet();
    void buildFullGardenerKit(); // Creative

private:
    OrderBuilder* builder; ///< The builder it directs.
};

#endif // ORDER_DIRECTOR_H