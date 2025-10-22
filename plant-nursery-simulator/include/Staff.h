#ifndef STAFF_H
#define STAFF_H

#include "Observer.h" // Is-a Observer
#include "Colleague.h" // Is-a Colleague
#include <string>
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
    void update(Subject* subject) override;

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
};

#endif // STAFF_H//