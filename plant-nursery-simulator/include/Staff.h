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
enum class StaffReminderType {
    Care,
    Availability,
    Message
};

struct StaffReminder {
    StaffReminderType type; ///< Category of the reminder.
    std::string message;    ///< Text shown to staff.
};

class Staff : public Observer, public Colleague {
public:
    /**
     * @brief Creates a staff colleague registered with the mediator.
     * @param id Unique identifier assigned to the staff member.
     * @param mediator Mediator that coordinates staff communication.
     */
    Staff(int id, FloorMediator* mediator);

    /**
     * @brief Cleans up outstanding commands and observer links.
     */
    ~Staff();

    // === Observer Method ===
    /**
     * @brief Reacts to observer notifications originating from plants.
     * @param event Event payload emitted by the subject.
     */
    void update(const ObserverEvent& event) override;

    // === Colleague Methods ===
    /**
     * @brief Retrieves the staff member's colleague identifier.
     * @return Numeric ID.
     */
    int getID() const override;

    /**
     * @brief Sends a mediated message to another colleague.
     * @param message Content to dispatch.
     * @param colleagueID Recipient colleague identifier.
     */
    void send(std::string message, int colleagueID) override;

    /**
     * @brief Receives a message routed through the mediator.
     * @param message Message body delivered to this staff member.
     */
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
     * @brief Creative Function: Number of outstanding reminders generated via observer updates.
     * @return Count of recorded reminders.
     */
    int getCareReminderCount() const;
    /**
     * @brief Creative Function: Retrieve the stored reminders.
     * @return Collection of reminder records.
     */
    const std::vector<StaffReminder>& getCareReminders() const;

    /**
     * @brief Subscribes this staff member to a plant's observer feed.
     * @param plant Plant instance to observe; ignored when nullptr.
     * @note The pointer is borrowed; the plant must outlive the staff member or emit
     *       `SubjectDestroyed` to trigger automatic detachment.
     */
    void observePlant(PlantInstance* plant);

    /**
     * @brief Stops observing the specified plant.
     * @param plant Plant instance to stop observing; ignored when nullptr.
     */
    void stopObservingPlant(PlantInstance* plant);

    // === Chain of Responsibility (Client) Methods ===
    /**
     * @brief Configures the first handler in the care request chain.
     * @note Pointer is non-owning; callers manage handler lifetime.
     */
    void setCareHandler(CareRequestHandler* h);

    /**
     * @brief Issues a care request that will be processed by the handler chain.
     * @param plant Plant instance needing attention.
     * @param requestType Logical action identifier (e.g., \"water\").
     */
    void makeCareRequest(PlantInstance* plant, std::string requestType);

    // === Creative Functions ===
    /**
     * @brief Assigns this staff member to a specific greenhouse bed.
     * @param bed The bed to assign (non-owning pointer).
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
    CareRequestHandler* handler; ///< Start of the CoR chain (non-owning)
    GreenhouseBed* assignedBed; ///< Bed this staff is responsible for (non-owning)
    std::vector<StaffReminder> careReminders; ///< Observer-generated reminders
    std::unordered_set<PlantInstance*> observedPlants; ///< Borrowed plant pointers currently observed

    /**
     * @brief Detaches from all currently observed plant subjects.
     */
    void stopObservingAll();
};

#endif // STAFF_H//
