#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Colleague.h"
#include <string>

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

private:
    int id;
    std::string name;

/* NOTE
    
    Customer has a name field but the constructor doesn’t take a name. 

*/
    // std::vector<StockItem*> shoppingCart; // Example of creative addition
};

#endif // CUSTOMER_H