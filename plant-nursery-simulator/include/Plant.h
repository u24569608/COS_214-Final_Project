#ifndef PLANT_H
#define PLANT_H

#include <string>

/**
 * @file Plant.h
 * @brief Abstract 'Prototype' interface for all plant types.
 */
class Plant {
public:
    virtual ~Plant();

    /**
     * @brief Creates a deep copy of this plant prototype.
     * @return Plant* A pointer to the newly cloned plant.
     */
    virtual Plant* clone() const = 0;

    virtual std::string getName() const = 0;
    virtual std::string getType() const = 0;

    /**
     * @brief Creative Function: Gets the ideal sunlight for this plant.
     * @return std::string (e.g., "Full Sun", "Partial Shade").
     */
    virtual std::string getRequiredSunlight() const = 0;

    /**
     * @brief Creative Function: Gets the native environment.
     * @return std::string (e.g., "Tropical", "Desert", "Temperate").
     */
    virtual std::string getNativeEnvironment() const = 0;

protected:
    std::string name;
    std::string type;
};

#endif // PLANT_H