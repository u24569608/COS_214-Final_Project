#ifndef INVENTORY_H
#define INVENTORY_H

#include "InventoryCollection.h"
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>

// Forward declarations
class PlantInstance;
class InventoryIterator;
class FileAdapter;
class StockItem;
class GreenhouseBed;
class PlantPrototypeRegistry;
class Plant;

/**
 * @file Inventory.h
 * @brief The 'ConcreteAggregate' class. Holds all plants.
 */
class Inventory : public InventoryCollection {
public:
    Inventory();
    ~Inventory();

    InventoryIterator* createIterator() override;

    void additem(StockItem* plant);

    /**
     * @brief Creative Function: Removes a plant from inventory.
     * @param name The plant name to remove.
     */
    void removeItem(std::string name);

    /**
     * @brief Removes a specific stock instance by its identifier.
     * @param id Unique identifier of the item to remove.
     * @return True when the item existed and was erased.
     */
    bool removeItemById(const std::string& id);

    /**
     * @brief Creative Function: Gets total stock for a plant type.
     * @param plantType The name of the plant (e.g., "Rose").
     * @return int The number of that plant in stock.
     */
    int getStockCount(std::string plantType) const;

    /**
     * @brief Creative Function: Finds a plant by its name.
     * @param name to search for.
     * @return StockItem* The plant, or nullptr if not found.
     */
    StockItem* findItem(std::string name);

    /**
     * @brief Retrieves a stock entry by its unique identifier.
     * @param id Stable identifier previously assigned to the item.
     * @return Pointer to the stock item or nullptr when not tracked.
     */
    StockItem* findItemById(const std::string& id) const;
    
    /**
     * @brief Uses the Adapter to load inventory from a file.
     * @param adapter The file reader adapter to use.
     * @param filePath The path to the file.
     */
    void loadFromFile(FileAdapter* adapter, std::string filePath);

    void saveToFile(FileAdapter* adapter, std::string filePath);

    /**
     * @brief Sets the greenhouse root bed that should receive managed plants.
     */
    void setGreenhouseRoot(GreenhouseBed* root);

    /**
     * @brief Retrieves the currently configured greenhouse bed.
     */
    GreenhouseBed* getGreenhouseRoot() const;

    /**
     * @brief Assigns the prototype registry used to materialise plant instances.
     */
    void setPlantRegistry(PlantPrototypeRegistry* registry);

    /**
     * @brief Provides read-only access to the configured plant prototype registry.
     */
    PlantPrototypeRegistry* getPlantRegistry() const;

    /**
     * @brief Registers a plant name as requiring a greenhouse-backed instance when loaded.
     * @param plantName Canonical name to treat as a plant entry.
     */
    void registerPlantType(const std::string& plantName);

    /**
     * @brief Clears all manually registered plant names.
     */
    void clearPlantTypes();

    /**
     * @brief Determines whether the supplied stock name should map to a plant instance.
     */
    bool isPlantType(const std::string& plantName) const;

    /**
     * @brief Creates and tracks a greenhouse-backed plant instance for a stock item.
     * @return Pointer to the new PlantInstance, or nullptr when no instance is needed.
     */
    PlantInstance* createPlantInstance(const std::string& plantName);

    // Friend class needed for iterator implementation
    friend class ConcreteInventoryIterator;

private:
    std::vector<StockItem*> items; ///< The underlying data structure.
    GreenhouseBed* greenhouseRoot;
    PlantPrototypeRegistry* plantRegistry;
    std::unordered_set<std::string> registeredPlantTypes;
    std::unordered_set<PlantInstance*> greenhousePlants;
    std::unordered_set<PlantInstance*> ownedPlantSet;
    std::vector<PlantInstance*> ownedPlants;
    std::unordered_map<PlantInstance*, std::unique_ptr<Plant>> prototypeOwners;
    std::unordered_map<std::string, int> plantInstanceCounters;
    std::unordered_map<std::string, StockItem*> itemsById;

    void registerPlant(PlantInstance* plant, bool takeOwnership);
    void releaseManagedPlants();
    void unregisterPlant(PlantInstance* plant);
};

#endif // INVENTORY_H
