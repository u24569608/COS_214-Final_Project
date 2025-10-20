#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <string>

// Forward declaration
class FloorMediator; 

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
};

#endif // COLLEAGUE_H