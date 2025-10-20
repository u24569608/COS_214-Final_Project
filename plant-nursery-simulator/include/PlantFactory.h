#ifndef PLANT_FACTORY_H
#define PLANT_FACTORY_H

#include <string>

// Forward declarations
class Plant;
class PlantPrototypeRegistry;

/**
 * @file PlantFactory.h
 * @brief Abstract factory for creating plants. (FR3, FR4)
 */
class PlantFactory {
public:
    virtual ~PlantFactory();
    
    /**
     * @brief Abstract factory method.
     * @return Plant* A pointer to a new Plant object.
     */
    virtual Plant* createPlant() const = 0;

    /**
     * @brief Factory method that uses the prototype registry.
     * @param type The string identifier of the plant to create.
     * @param registry A reference to the prototype registry.
     * @return Plant* A pointer to a new (cloned) Plant object.
     */
    Plant* createPlantFromPrototype(std::string type, PlantPrototypeRegistry& registry);
};

#endif // PLANT_FACTORY_H