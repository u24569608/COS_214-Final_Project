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
     * @param plant A unique_ptr owning the prototype instance.
     */
    void addPrototype(const std::string& name, std::unique_ptr<Plant> plant);

    /**
     * @brief Clones a plant from the registry.
     * @param name The key of the prototype to clone. 
     * @param type Optional override for the clone's type classification.
     * @return Plant* A new clone, or nullptr if not found.
     */
    Plant* createPlant(const std::string& name, const std::string& type);

private:
    std::map<std::string, std::unique_ptr<Plant>> prototypes;
};

#endif // PLANT_PROTOTYPE_REGISTRY_H
