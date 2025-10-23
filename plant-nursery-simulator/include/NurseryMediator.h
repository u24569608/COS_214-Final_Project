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
    NurseryMediator();
    void addColleague(Colleague* colleague) override;
    void distribute(std::string message, int senderID, int recipientID) override;
private:
    std::vector<Colleague*> colleagues; // List of all Colleagues.
};

#endif // NURSERY_MEDIATOR_H