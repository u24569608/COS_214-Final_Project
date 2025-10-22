#ifndef INVENTORY_H
#define INVENTORY_H

#include "InventoryCollection.h"
#include <vector>
#include <string>

// Forward declarations
class PlantInstance;
class InventoryIterator;
class FileReaderAdapter;

/**
 * @file Inventory.h
 * @brief The 'ConcreteAggregate' class. Holds all plants.
 */
class Inventory : public InventoryCollection {
public:
    Inventory();
    ~Inventory();

    InventoryIterator* createIterator() override;

    void addPlant(PlantInstance* plant);

    /**
     * @brief Creative Function: Removes a plant from inventory.
     * @param plant The plant instance to remove.
     */
    void removePlantFromStock(PlantInstance* plant);

    /**
     * @brief Creative Function: Gets total stock for a plant type.
     * @param plantType The name of the plant (e.g., "Rose").
     * @return int The number of that plant in stock.
     */
    int getStockCount(std::string plantType) const;

    /**
     * @brief Creative Function: Finds a plant by a unique ID.
     * @param id The ID to search for.
     * @return PlantInstance* The plant, or nullptr if not found.
     */
    PlantInstance* findPlantByID(int id);
    
    /**
     * @brief Uses the Adapter to load inventory from a file.
     * @param adapter The file reader adapter to use.
     * @param filePath The path to the file.
     */
    void loadFromFile(FileReaderAdapter* adapter, std::string filePath);

    // Friend class needed for iterator implementation
    friend class ConcreteInventoryIterator;

private:
    std::vector<PlantInstance*> plants; ///< The underlying data structure.
};

#endif // INVENTORY_H