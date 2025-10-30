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
    /**
     * @brief Allows builder destruction through interface pointers.
     */
    virtual ~OrderBuilder();

    /**
     * @brief Releases ownership of the constructed order to the caller.
     * @return Raw pointer to the built order, or nullptr if none created yet.
     * @note Caller assumes responsibility for deleting the returned pointer.
     */
    Order* getOrder();

    /**
     * @brief Initializes a fresh order instance ready for population.
     */
    void createNewOrder();

    /**
     * @brief Inserts a stock item into the order being assembled.
     * @param item Pointer to the stock item under construction.
     */
    virtual void addItem(StockItem* item) = 0 ;

protected:
    std::unique_ptr<Order> order;
};

#endif // ORDER_BUILDER_H
