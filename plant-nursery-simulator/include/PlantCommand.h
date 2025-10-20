#ifndef PLANT_COMMAND_H
#define PLANT_COMMAND_H

// Forward declaration
class PlantInstance;

/**
 * @file PlantCommand.h
 * @brief The 'Command' interface. (FR18)
 */
class PlantCommand {
public:
    virtual ~PlantCommand();
    virtual void execute() = 0;
protected:
    PlantCommand(PlantInstance* p);
    PlantInstance* plant; ///< The 'Receiver' of the command.
};

#endif // PLANT_COMMAND_H