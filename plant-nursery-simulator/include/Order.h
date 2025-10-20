#ifndef ORDER_H
#define ORDER_H

#include "StockItem.h" // Holds StockItems
#include <vector>
#include <string>

/**
 * @file Order.h
 * @brief The complex 'Product' of the Builder pattern.
 */
class Order {
public:
    Order();
    
    void addItem(StockItem item);
    void showOrder() const;

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

private:
    std::vector<StockItem> items; ///< The parts of the complex object.
    std::string status;
    int orderID;
};

#endif // ORDER_H