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
    /**
     * @brief Constructs a director with no builder assigned.
     */
    OrderDirector();

    /**
     * @brief Cleans up any partially constructed products when the director is destroyed.
     */
    ~OrderDirector(); // <-- ADDED: To prevent memory leaks
    
    /**
     * @brief Instantiates a fresh concrete builder managed by the director.
     * @note Replaces and deletes any previously assigned builder.
     */
    void setBuilder();

    /**
     * @brief Retrieves the finished order from the active builder.
     * @return Pointer to the constructed product; caller takes ownership.
     */
    Order* getOrder(); // <-- ADDED: To retrieve the final product
    
    /**
     * @brief Orchestrates the creation of a curated gift basket.
     */
    void buildGiftBasket();

    /**
     * @brief Builds a starter kit aimed at beginner gardeners.
     */
    void buildBeginnerSet();

    /**
     * @brief Produces a comprehensive set of gardening supplies.
     */
    void buildFullGardenerKit(); // Creative

private:
    OrderBuilder* builder; ///< The builder it directs.
};

#endif // ORDER_DIRECTOR_H
