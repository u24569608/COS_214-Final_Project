#ifndef NURSERY_MEDIATOR_H
#define NURSERY_MEDIATOR_H

#include "FloorMediator.h"
#include <vector>
#include <string>

// Forward declaration
class Colleague;

/**
 * @file NurseryMediator.h
 * @brief The 'ConcreteMediator' implementation.
 */
class NurseryMediator : public FloorMediator {
public:
    /**
     * @brief Instantiates a mediator managing a shared nursery floor.
     */
    NurseryMediator();

    /**
     * @brief Registers a colleague so future messages can be routed to them.
     * @param colleague Pointer to the colleague joining the mediator.
     */
    void addColleague(Colleague* colleague) override;

    /**
     * @brief Delivers a message from a sender to a target colleague or broadcasts.
     * @param message Payload to distribute.
     * @param senderID Identifier of the colleague initiating the message.
     * @param recipientID Target colleague ID; use -1 to notify everyone.
     */
    void distribute(std::string message, int senderID, int recipientID) override;
private:
    std::vector<Colleague*> colleagues; ///< List of all Colleagues.
};

#endif // NURSERY_MEDIATOR_H
