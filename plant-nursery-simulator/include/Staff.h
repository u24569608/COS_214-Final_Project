#ifndef STAFF_H
#define STAFF_H

#include "Observer.h" // Is-a Observer
#include "Colleague.h" // Is-a Colleague
#include <string>
#include <unordered_set>
#include <vector>

// Forward declarations
class Subject;
class PlantInstance;
class PlantCommand;
class CareRequestHandler;
class GreenhouseBed;
class FloorMediator;

/**
 * @file Staff.h
 * @brief Represents a staff member. Links many patterns:
 * - ConcreteObserver (Observer Pattern) - FR13
 * - ConcreteColleague (Mediator Pattern) - FR17
 * - Invoker (Command Pattern) - FR19
 * - Client (Chain of Responsibility) - FR21
 */
class Staff : public Observer, public Colleague {
public:
    Staff(int id, FloorMediator* mediator);
    ~Staff();

    // === Observer Method ===
    void update(const ObserverEvent& event) override;

    // === Colleague Methods ===
    int getID() const override;
    void send(std::string message, int colleagueID) override;
    void receive(std::string message) override;

    // === Command (Invoker) Methods ===
    /**
     * @brief Adds a command to the staff's task queue. (FR19)
     * @param cmd The command to add.
     */
    void addCommandToQueue(PlantCommand* cmd);

    /**
     * @brief Creative Function: Executes the next command in the queue.
     */
    void processNextTask();

    /**
     * @brief Creative Function: Gets the number of pending tasks.
     * @return int The size of the task queue.
     */
    int getTaskQueueSize() const;
    /**
     * @brief Creative Function: Number of outstanding care reminders generated via observer updates.
     * @return Count of recorded reminders.
     */
    int getCareReminderCount() const;
    /**
     * @brief Creative Function: Retrieve the stored reminder messages.
     * @return Collection of reminder strings.
     */
    const std::vector<std::string>& getCareReminders() const;

    /**
     * @brief Subscribes this staff member to a plant's observer feed.
     * @param plant Plant instance to observe; ignored when nullptr.
     */
    void observePlant(PlantInstance* plant);

    /**
     * @brief Stops observing the specified plant.
     * @param plant Plant instance to stop observing; ignored when nullptr.
     */
    void stopObservingPlant(PlantInstance* plant);

    // === Chain of Responsibility (Client) Methods ===
    void setCareHandler(CareRequestHandler* h);
    void makeCareRequest(PlantInstance* plant, std::string requestType);

    // === Creative Functions ===
    /**
     * @brief Assigns this staff member to a specific greenhouse bed.
     * @param bed The bed to assign.
     */
    void assignToBed(GreenhouseBed* bed);

    /**
     * @brief Manually checks all plants in the assigned bed.
     */
    void checkOnPlants();

private:
    int id;
    std::string name;
    std::vector<PlantCommand*> taskQueue; ///< Command queue
    CareRequestHandler* handler; ///< Start of the CoR chain
    GreenhouseBed* assignedBed; ///< Bed this staff is responsible for
    std::vector<std::string> careReminders; ///< Observer-generated care reminders
    std::unordered_set<PlantInstance*> observedPlants; ///< Plants this staff keeps tabs on

    void stopObservingAll();
};

#endif // STAFF_H//
