#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>

#include "Observer.h"

/**
 * @file Subject.h
 * @brief Declares the Subject base that manages observer subscriptions. (FR13)
 */
class Subject {
public:
    /**
     * @brief Virtual default destructor for polymorphic cleanup.
     */
    virtual ~Subject() = default;

    /**
     * @brief Registers an observer to receive future notifications.
     * @param observer Instance interested in subject events.
     */
    virtual void attach(Observer* observer);

    /**
     * @brief Unregisters an observer from receiving notifications.
     * @param observer Instance that no longer requires updates.
     */
    virtual void detach(Observer* observer);

protected:
    /**
     * @brief Dispatches an event to all registered observers.
     * @param event Payload describing the change that occurred.
     */
    virtual void notify(const ObserverEvent& event);

private:
    std::list<Observer*> observers; ///< Subscribers to this subject.
};

#endif // SUBJECT_H
