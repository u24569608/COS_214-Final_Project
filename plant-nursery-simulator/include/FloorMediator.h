#ifndef FLOOR_MEDIATOR_H
#define FLOOR_MEDIATOR_H

#include <string>
//
// Forward declaration
class Colleague; 

/**
 * @file FloorMediator.h
 * @brief The 'Mediator' interface. (FR16)
 */
class FloorMediator {
public:
    /**
     * @brief Ensures derived mediators can be released polymorphically.
     */
    virtual ~FloorMediator() = default;

    /**
     * @brief Registers a colleague participant with the mediator.
     * @param colleague Pointer to the colleague to manage.
     */
    virtual void addColleague(Colleague* colleague) = 0;

    /**
     * @brief Routes a message from a sender to the intended recipient.
     * @param message The payload to deliver.
     * @param senderID Identifier of the colleague initiating the message.
     * @param recipientID Identifier of the target colleague; -1 for broadcast.
     */
    virtual void distribute(std::string message, int senderID, int recipientID) = 0;
};

#endif // FLOOR_MEDIATOR_H
