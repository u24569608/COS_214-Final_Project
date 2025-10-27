#include "../include/Subject.h"

#include <algorithm>
#include <optional>

Subject::~Subject() {
    if (!observers.empty()) {
        const ObserverEvent destroyEvent{
            ObserverEventType::SubjectDestroyed,
            this,
            "Subject destroyed, observers detached.",
            std::nullopt};
        notify(destroyEvent);
    }
    clearObservers();
}

void Subject::attach(Observer* observer) {
    if (!observer) {
        return;
    }

    const auto alreadyAttached = std::find(observers.begin(), observers.end(), observer);
    if (alreadyAttached == observers.end()) {
        observers.push_back(observer);
    }
}

void Subject::detach(Observer* observer) {
    observers.remove(observer);
}

void Subject::notify(const ObserverEvent& event) {
    auto snapshot = observers;
    for (Observer* observer : snapshot) {
        if (observer) {
            observer->update(event);
        }
    }
}

void Subject::clearObservers() {
    observers.clear();
}
