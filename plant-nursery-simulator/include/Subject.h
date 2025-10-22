#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>

// Forward declaration
class Observer; 

/**
 * @file Subject.h
 * @brief The 'Subject' interface. (FR13)
 */
class Subject {
public:
    virtual ~Subject();

    /**
     * @brief Attach (subscribe) an Observer.
     * @param observer The observer to attach.
     */
    virtual void attach(Observer* observer);

    /**
     * @brief Detach (unsubscribe) an Observer.
     * @param observer The observer to detach.
     */
    virtual void detach(Observer* observer);
    
protected:
    /**
     * @brief Notify all subscribed Observers of a change.
     */
    virtual void notify();

private:
    std::list<Observer*> observers; ///< List of subscribed Observers.
};

#endif // SUBJECT_H