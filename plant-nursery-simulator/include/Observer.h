#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

// Forward declaration to break circular dependency
class Subject;

/**
 * @file Observer.h
 * @brief Declares the Observer contract and shared event payload. (FR12)
 */
enum class ObserverEventType {
    AvailabilityChanged, ///< Subject availability toggled.
    CareRequired,        ///< Subject requires human intervention.
    Generic              ///< Fallback event type for miscellaneous notices.
};

/**
 * @brief Describes a notification emitted by a Subject.
 */
struct ObserverEvent {
    ObserverEventType type; ///< Classifies the event for observers.
    Subject* source;        ///< Subject instance responsible for the notification.
    std::string message;    ///< Human-readable context about the event.
};

/**
 * @brief The 'Observer' interface that reacts to Subject notifications.
 */
class Observer {
public:
    virtual ~Observer() = default;

    /**
     * @brief Called by the Subject whenever an event occurs.
     * @param event Payload containing the notification details.
     */
    virtual void update(const ObserverEvent& event) = 0;
};

#endif // OBSERVER_H
