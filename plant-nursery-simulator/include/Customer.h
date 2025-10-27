#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Colleague.h"
#include <string>
#include <vector>

// Forward declarations
class InventoryIterator;
class StockItem;

/**
 * @file Customer.h
 * @brief The 'ConcreteColleague' for Customers.
 */
class Customer : public Colleague {
public:
    Customer(int id, FloorMediator* mediator);

    int getID() const override;
    void send(std::string message, int colleagueID) override;
    void receive(std::string message) override;

    /**
     * @brief Creative Function: Customer requests help from staff.
     */
    void askForHelp();

    /**
     * @brief Creative Function: Customer browses the inventory.
     * @param iter An iterator for the inventory.
     */
    void browseInventory(InventoryIterator* iter);

    /**
     * @brief Creative Function: Customer adds an item to their cart.
     * @param item The item to add.
     */
    void addToCart(StockItem* item);

    /**
     * @brief Removes an item reference from the cart by direct pointer.
     * @return True when an entry was removed.
     */
    bool removeFromCart(StockItem* item);

    /**
     * @brief Removes all cart entries that match the supplied stock name.
     * @return True when at least one entry was removed.
     */
    bool removeFromCart(const std::string& itemName);

    /**
     * @brief Prunes entries that are no longer available for purchase.
     */
    void clearUnavailableItems();

    /**
     * @brief Notification hook used by SalesFacade when stock is sold elsewhere.
     */
    void notifyItemSold(const std::string& itemName);

    /**
     * @brief Summarises the current cart contents by stock name.
     */
    std::vector<std::string> getCartSummary() const;

    /**
     * @brief Copies the active cart item pointers for advanced operations.
     */
    std::vector<StockItem*> getCartItems() const;

    /**
     * @brief Returns the number of entries currently held in the cart.
     */
    size_t getCartSize() const;

private:
    struct CartEntry {
        std::string name;
        StockItem* item;
    };

    bool containsItem(StockItem* item) const;
    bool containsItem(const std::string& itemName) const;

    int id;
    std::string name;
    std::vector<CartEntry> shoppingCart;
};

#endif // CUSTOMER_H
