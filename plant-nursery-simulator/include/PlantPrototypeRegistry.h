#ifndef PLANT_PROTOTYPE_REGISTRY_H
#define PLANT_PROTOTYPE_REGISTRY_H

#include <map>
#include <memory>
#include <string>
#include <vector>

// Forward declaration
class Plant;

/**
 * @file PlantPrototypeRegistry.h
 * @brief Manages a set of clonable plant prototypes. (FR1, FR2)
 */
class PlantPrototypeRegistry {
public:
    /**
     * @brief Creates an empty registry ready to store plant prototypes.
     */
    PlantPrototypeRegistry();

    /**
     * @brief Releases owned prototypes and clears the registry.
     */
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

    /**
     * @brief Checks whether a prototype exists for the supplied plant name.
     * @param name The lookup key.
     * @return True if a prototype is registered and non-null.
     */
    bool hasPrototype(const std::string& name) const;

    /**
     * @brief Enumerates the registered prototype names for UI population.
     * @return Vector of prototype identifiers sorted by insertion order.
     */
    std::vector<std::string> listPrototypes() const;

private:
    std::map<std::string, std::unique_ptr<Plant>> prototypes;
};

#endif // PLANT_PROTOTYPE_REGISTRY_H
