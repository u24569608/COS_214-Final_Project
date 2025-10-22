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
    virtual ~FloorMediator();
    virtual void addColleague(Colleague* colleague) = 0;
    virtual void distribute(std::string message, int senderID, int recipientID) = 0;
};

#endif // FLOOR_MEDIATOR_H