#ifndef OBSERVER_H
#define OBSERVER_H

// Forward declaration to break circular dependency
class Subject; 

/**
 * @file Observer.h
 * @brief The 'Observer' interface. (FR12)
 */
class Observer {
public:
    virtual ~Observer();
    /**
     * @brief The update method called by the Subject.
     * @param subject The Subject that sent the notification.
     */
    virtual void update(Subject* subject) = 0;
};

#endif // OBSERVER_H//