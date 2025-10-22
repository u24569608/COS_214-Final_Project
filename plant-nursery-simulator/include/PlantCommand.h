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
    PlantCommand(PlantInstance* p);
    virtual ~PlantCommand();
    virtual void handleRequest() = 0;
protected:
    
    PlantInstance* plant; ///< The 'Receiver' of the command.
};

#endif // PLANT_COMMAND_H