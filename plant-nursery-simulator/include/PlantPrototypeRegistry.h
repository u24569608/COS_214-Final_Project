#ifndef PLANT_PROTOTYPE_REGISTRY_H
#define PLANT_PROTOTYPE_REGISTRY_H

#include <map>
#include <string>
#include <memory>

// Forward declaration
class Plant;

/**
 * @file PlantPrototypeRegistry.h
 * @brief Manages a set of clonable plant prototypes. (FR1, FR2)
 */
class PlantPrototypeRegistry {
public:
    PlantPrototypeRegistry();
    ~PlantPrototypeRegistry();

    /**
     * @brief Adds a plant prototype to the registry.
     * @param name The key to store the prototype under.
     * @param plant A pointer to the prototype.
     */
    void addPrototype(std::string name, Plant* plant);

    /**
     * @brief Clones a plant from the registry.
     * @param name The key of the prototype to clone. 
     * @param type the type of plant to clone.
     * @return Plant* A new clone, or nullptr if not found.
     */
    Plant* createPlant(std::string name, std::string type);

private:
    std::map<std::string, std::unique_ptr<Plant>> prototypes;
};

#endif // PLANT_PROTOTYPE_REGISTRY_H