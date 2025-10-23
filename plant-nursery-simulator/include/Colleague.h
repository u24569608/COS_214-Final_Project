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
    Colleague(FloorMediator* mediator);
    virtual ~Colleague();

    virtual void send(std::string message, int colleagueID) = 0;
    virtual void receive(std::string message) = 0;
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