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
    /**
     * @brief Adds a stock entry to the cart using facade-provided metadata.
     * @note Prefer using SalesFacade::addItemToCart so that notification hooks are registered.
     * @param item Reference to the live stock record being tracked.
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
     * @brief Removes the entry matching a specific stock identifier.
     * @param itemId Stable identifier assigned by the inventory system.
     * @return True when a matching entry was pruned.
     */
    bool removeFromCartById(const std::string& itemId);

    /**
     * @brief Prunes entries that are no longer available for purchase.
     */
    void clearUnavailableItems();

    /**
     * @brief Notification hook used by SalesFacade when stock is sold elsewhere.
     */
    void notifyItemSold(const std::string& itemId, const std::string& itemName);

    /**
     * @brief Summarises the current cart contents by stock name.
     */
    std::vector<std::string> getCartSummary() const;

    /**
     * @brief Copies the active cart item identifiers for advanced operations.
     */
    std::vector<std::string> getCartItemIds() const;

    /**
     * @brief Returns the number of entries currently held in the cart.
     */
    size_t getCartSize() const;

private:
    struct CartEntry {
        std::string name;
        std::string itemId;
        bool isAvailable;
        std::string displayStatus;
    };

    bool containsItem(StockItem* item) const;
    bool containsItemId(const std::string& itemId) const;
    bool containsItem(const std::string& itemName) const;

    int id;
    std::string name;
    std::vector<CartEntry> shoppingCart;
};

#endif // CUSTOMER_H
