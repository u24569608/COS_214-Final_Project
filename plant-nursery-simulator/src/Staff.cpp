#include "../include/Staff.h"

#include "../include/CareRequestHandler.h"
#include "../include/FloorMediator.h"
#include "../include/GreenhouseBed.h"
#include "../include/PlantCommand.h"
#include "../include/PlantInstance.h"

#include <string>
#include <utility>

namespace {
std::string buildReminderMessage(const ObserverEvent& event) {
    if (event.source == nullptr) {
        return event.message;
    }

    const auto* plant = dynamic_cast<PlantInstance*>(event.source);
    if (plant == nullptr) {
        return event.message;
    }

    const std::string plantName = plant->getPlantTypeName() + " (" + plant->getName() + ")";
    if (event.message.empty()) {
        return "Care requested for " + plantName;
    }
    return plantName + ": " + event.message;
}
} // namespace

Staff::Staff(int id, FloorMediator* mediator)
    : Colleague(mediator),
      id(id),
      name("Staff " + std::to_string(id)),
      handler(nullptr),
      assignedBed(nullptr) {
}

Staff::~Staff() = default;

void Staff::update(const ObserverEvent& event) {
    switch (event.type) {
    case ObserverEventType::CareRequired: {
        careReminders.push_back(buildReminderMessage(event));
        break;
    }
    case ObserverEventType::AvailabilityChanged: {
        // Availability changes trigger a lighter reminder to review tasks.
        careReminders.push_back("Availability update: " + event.message);
        break;
    }
    default:
        break;
    }
}

int Staff::getID() const {
    return id;
}

void Staff::send(std::string message, int colleagueID) {
    if (mediator == nullptr) {
        return;
    }
    mediator->distribute(std::move(message), id, colleagueID);
}

void Staff::receive(std::string message) {
    careReminders.push_back("Message: " + message);
}

void Staff::addCommandToQueue(PlantCommand* cmd) {
    if (cmd == nullptr) {
        return;
    }
    taskQueue.push_back(cmd);
}

void Staff::processNextTask() {
    if (taskQueue.empty()) {
        return;
    }
    PlantCommand* next = taskQueue.front();
    taskQueue.erase(taskQueue.begin());
    if (next != nullptr) {
        next->handleRequest();
    }
}

int Staff::getTaskQueueSize() const {
    return static_cast<int>(taskQueue.size());
}

int Staff::getCareReminderCount() const {
    return static_cast<int>(careReminders.size());
}

const std::vector<std::string>& Staff::getCareReminders() const {
    return careReminders;
}

void Staff::setCareHandler(CareRequestHandler* h) {
    handler = h;
}

void Staff::makeCareRequest(PlantInstance* plant, std::string requestType) {
    if (handler != nullptr) {
        handler->handleRequest(plant, std::move(requestType));
    } else {
        careReminders.push_back("Unhandled care request: " + requestType);
    }
}

void Staff::assignToBed(GreenhouseBed* bed) {
    assignedBed = bed;
}

void Staff::checkOnPlants() {
    if (assignedBed != nullptr) {
        assignedBed->performCare();
    }
}
