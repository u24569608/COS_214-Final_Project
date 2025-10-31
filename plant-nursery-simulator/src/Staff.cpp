/**
 * @file Staff.cpp
 * @brief Implements the Staff behaviour defined in the corresponding header.
 */

#include "../include/Staff.h"

#include "../include/CareRequestHandler.h"
#include "../include/FloorMediator.h"
#include "../include/GreenhouseBed.h"
#include "../include/PlantCommand.h"
#include "../include/PlantInstance.h"
#include "../include/WaterPlant.h"
#include "../include/FertilizePlant.h"

#include <string>
#include <sstream>
#include <utility>
#include <vector>

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

Staff::~Staff() {
    stopObservingAll();
}

void Staff::update(const ObserverEvent& event) {
    if (event.type == ObserverEventType::SubjectDestroyed) {
        PlantInstance* retired = event.source != nullptr
                                     ? static_cast<PlantInstance*>(event.source)
                                     : nullptr;
        if (retired != nullptr) {
            observedPlants.erase(retired);
            removeCommandsForPlant(retired);
        }
        if (!event.message.empty()) {
            careReminders.push_back({StaffReminderType::Message, event.message});
        }
        return;
    }

    PlantInstance* plant = event.source ? dynamic_cast<PlantInstance*>(event.source) : nullptr;
    const bool hasTrackedPlants = !observedPlants.empty();

    if (plant) {
        if (hasTrackedPlants && observedPlants.count(plant) == 0) {
            return;
        }
    } else if (hasTrackedPlants) {
        // Ignore broadcasts unrelated to tracked plants.
        return;
    }

    if (event.type == ObserverEventType::CareRequired) {
        const std::string reminder = buildReminderMessage(event);
        careReminders.push_back({StaffReminderType::Care, reminder});
        if (plant != nullptr) {
            enqueueCareTasks(plant);
        }
        log(name + " received care request: " + reminder);
        return;
    }

    if (event.type == ObserverEventType::AvailabilityChanged) {
        std::string message = event.message;
        if (message.empty() && event.availability.has_value()) {
            const bool available = *event.availability == AvailabilityStatus::Available;
            message = available ? "Plant ready for sale" : "Plant unavailable for sale";
        }
        careReminders.push_back({StaffReminderType::Availability,
                                 buildReminderMessage({ObserverEventType::CareRequired,
                                                       event.source,
                                                       message,
                                                       event.availability})});
        log(name + " received availability update: " + message);
        return;
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
    careReminders.push_back({StaffReminderType::Message, "Message: " + message});
    log(name + " received message: " + message);
}

void Staff::addCommandToQueue(std::unique_ptr<PlantCommand> cmd) {
    if (!cmd) {
        return;
    }
    PlantInstance* target = cmd->getTarget();
    std::ostringstream oss;
    oss << name << " queued " << cmd->getCommandName();
    if (target != nullptr) {
        oss << " for " << target->getPlantTypeName() << " (" << target->getName() << ")";
    }
    taskQueue.push_back(std::move(cmd));
    log(oss.str());
}

PlantInstance* Staff::processNextTask() {
    if (taskQueue.empty()) {
        log(name + " has no tasks to process");
        return nullptr;
    }
    std::unique_ptr<PlantCommand> next = std::move(taskQueue.front());
    taskQueue.pop_front();

    PlantInstance* target = next ? next->getTarget() : nullptr;
    std::string label = next ? next->getCommandName() : "Task";
    if (next) {
        next->handleRequest();
    }

    std::ostringstream oss;
    oss << name << " processed " << label;
    if (target != nullptr) {
        oss << " for " << target->getPlantTypeName() << " (" << target->getName() << ")";
    }
    log(oss.str());
    return target;
}

int Staff::getTaskQueueSize() const {
    return static_cast<int>(taskQueue.size());
}

int Staff::getCareReminderCount() const {
    return static_cast<int>(careReminders.size());
}

const std::vector<StaffReminder>& Staff::getCareReminders() const {
    return careReminders;
}

std::vector<std::string> Staff::describePendingTasks() const {
    std::vector<std::string> descriptions;
    descriptions.reserve(taskQueue.size());
    for (const auto& command : taskQueue) {
        if (!command) {
            continue;
        }
        std::string line = command->getCommandName();
        if (PlantInstance* target = command->getTarget()) {
            std::string typeName = target->getPlantTypeName();
            if (typeName.empty()) {
                typeName = target->getName();
            }
            line += " - ";
            line += typeName;
            line += " (";
            line += target->getName();
            line += ")";
        }
        descriptions.push_back(std::move(line));
    }
    return descriptions;
}

bool Staff::removeCommandsForPlant(PlantInstance* plant) {
    if (plant == nullptr || taskQueue.empty()) {
        return false;
    }

    bool removed = false;
    for (auto it = taskQueue.begin(); it != taskQueue.end();) {
        PlantInstance* target = (*it) ? (*it)->getTarget() : nullptr;
        if (target == plant) {
            it = taskQueue.erase(it);
            removed = true;
        } else {
            ++it;
        }
    }

    if (removed) {
        log(name + " removed pending tasks for a retired plant.");
    }
    return removed;
}

void Staff::setLogSink(std::function<void(const std::string&)> sink) {
    logSink = std::move(sink);
}

void Staff::observePlant(PlantInstance* plant) {
    if (plant == nullptr) {
        return;
    }
    const bool inserted = observedPlants.insert(plant).second;
    if (inserted) {
        plant->attach(this);
    }
}

void Staff::stopObservingPlant(PlantInstance* plant) {
    if (plant == nullptr) {
        return;
    }
    const auto it = observedPlants.find(plant);
    if (it != observedPlants.end()) {
        plant->detach(this);
        observedPlants.erase(it);
    }
}

void Staff::setCareHandler(CareRequestHandler* h) {
    handler = h;
}

void Staff::makeCareRequest(PlantInstance* plant, std::string requestType) {
    if (handler != nullptr) {
        handler->handleRequest(plant, std::move(requestType));
    } else {
        careReminders.push_back({StaffReminderType::Message,
                                 "Unhandled care request: " + requestType});
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

void Staff::stopObservingAll() {
    if (observedPlants.empty()) {
        return;
    }
    std::vector<PlantInstance*> snapshot(observedPlants.begin(), observedPlants.end());
    for (PlantInstance* plant : snapshot) {
        if (plant != nullptr) {
            plant->detach(this);
        }
    }
    observedPlants.clear();
}

void Staff::log(const std::string& message) const {
    if (logSink) {
        logSink(message);
    }
}

void Staff::enqueueCareTasks(PlantInstance* plant) {
    if (plant == nullptr) {
        return;
    }

    if (plant->isThirsty()) {
        addCommandToQueue(std::make_unique<WaterPlant>(plant));
    }
    if (plant->needsFertilizing()) {
        addCommandToQueue(std::make_unique<FertilizePlant>(plant));
    }
}
