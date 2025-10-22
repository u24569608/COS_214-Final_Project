#ifndef SALES_FACADE_H
#define SALES_FACADE_H

#include <string>
#include <vector>

// Forward declarations for subsystem pointers
class Inventory;
class PaymentProcessor;
class Customer;
class PlantInstance;
class Order;
class OrderBuilder;
class StockItem;

/**
 * @file SalesFacade.h
 * @brief The 'Facade' class.
 * @details Provides a simple interface to a complex sales subsystem.
 */
class SalesFacade {
public:
    SalesFacade(Inventory* inv, PaymentProcessor* pp, OrderBuilder* ob);

    /**
     * @brief Simplifies buying a single item at the counter.
     * @return bool True if the sale was successful.
     */
    bool purchaseItem(Customer* customer, StockItem* item);

    /**
     * @brief Creative Function: Processes a complex custom order.
     * @return Order* The finalized order, or nullptr if failed.
     */
    Order* buildAndFinalizeOrder(Customer* customer, std::vector<StockItem> items);

    /**
     * @brief Creative Function: Processes a return.
     * @param order The order to be returned.
     * @return bool True if the return was successful.
     */
    bool processReturn(Order* order);

    /**
     * @brief Creative Function: Checks stock level for an item.
     * @param plantType The name of the plant.
     * @return int The number in stock.
     */
    int checkStock(std::string plantType);

    void addItemToInventory(std::string name, double price);

private:
    Inventory* inventory; ///< Subsystem 1
    PaymentProcessor* paymentProcessor; ///< Subsystem 2
    OrderBuilder* orderBuilder; ///< Subsystem 3
};

#endif // SALES_FACADE_H