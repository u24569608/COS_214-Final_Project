#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <string>

// Forward declaration
class FloorMediator; 
class Inventory;

/**
 * @file Colleague.h
 * @brief The 'Colleague' interface. (FR17)
 */
class Colleague {
public:
    /**
     * @brief Constructs a colleague participant registered with the mediator.
     * @param mediator Mediator responsible for coordinating colleague interaction.
     */
    Colleague(FloorMediator* mediator);
    virtual ~Colleague();

    /**
     * @brief Sends a message through the mediator to a colleague.
     * @param message The content to dispatch.
     * @param colleagueID Identifier for the intended recipient.
     */
    virtual void send(std::string message, int colleagueID) = 0;

    /**
     * @brief Receives a message routed by the mediator.
     * @param message Text received from another colleague.
     */
    virtual void receive(std::string message) = 0;

    /**
     * @brief Retrieves the identifier assigned to this colleague.
     * @return Numeric ID used by the mediator for routing.
     */
    virtual int getID() const = 0;

protected:
    FloorMediator* mediator; ///< Pointer to the Mediator.

/* NOTE 

    Customer cannot reach the mediator pointer
    But Customer::send(...) must call the mediator (e.g., mediator->distribute(...)). 
    Because mediator is private, the derived class (Customer) cannot access it, 
    and there’s no getter.
    CHANGED FROM PRIVATE TO PROTECTED
*/

private: 
    Inventory* inventory; ///< Pointer to the inventory.
};

#endif // COLLEAGUE_H
