#ifndef ORDER_H
#define ORDER_H
//
#include "StockItem.h" // Holds StockItems
#include <vector>
#include <string>

/**
 * @file Order.h
 * @brief The complex 'Product' of the Builder pattern.
 */
class Order {
public:
    /**
     * @brief Creates an empty order ready to receive stock items.
     */
    Order();

    /**
     * @brief Appends a stock item copy to the order contents.
     * @param item Stock entry describing the purchased product.
     */
    void addItem(StockItem item);

    /**
     * @brief Writes a human-readable summary of the order to stdout.
     */
    void printOrder() const;

    /**
     * @brief Creative Function: Calculates the total price of the order.
     * @return double The total price.
     */
    double calculateTotal() const;

    /**
     * @brief Creative Function: Gets the current status of the order.
     * @return std::string (e.g., "Pending", "Paid", "Shipped").
     */
    std::string getOrderStatus() const;
    
    /**
     * @brief Creative Function: Updates the order status.
     * @param newStatus The new status.
     */
    void setOrderStatus(std::string newStatus);

    /**
     * @brief Provides read-only access to the contained order items.
     * @return Const reference to the aggregated stock items.
     */
    const std::vector<StockItem>& getItems() const;

private:
    std::vector<StockItem> items; ///< The parts of the complex object.
    std::string status;
    int orderID;
};

#endif // ORDER_H
