#ifndef PLANT_COMMAND_H
#define PLANT_COMMAND_H

#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file PlantCommand.h
 * @brief The 'Command' interface. (FR18)
 */
class PlantCommand {
public:
    /**
     * @brief Creates a command bound to a specific plant receiver.
     * @param p Target plant instance operated on by derived commands.
     */
    PlantCommand(PlantInstance* p);

    /**
     * @brief Ensures derived commands clean up via base pointers.
     */
    virtual ~PlantCommand();

    /**
     * @brief Executes the command-specific request against the receiver.
     */
    virtual void handleRequest() = 0;

    /**
     * @brief Exposes the plant receiver for observers of the command queue.
     * @return Borrowed pointer to the bound plant instance.
     */
    PlantInstance* getTarget() const;

    /**
     * @brief Provides a human readable label for logging.
     * @return Short command description (e.g. "Water Plant").
     */
    virtual std::string getCommandName() const = 0;

protected:
    PlantInstance* plant; ///< The 'Receiver' of the command.
};

#endif // PLANT_COMMAND_H
