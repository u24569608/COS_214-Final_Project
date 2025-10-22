#ifndef INVENTORY_H
#define INVENTORY_H

#include "InventoryCollection.h"
#include <vector>
#include <string>

// Forward declarations
class PlantInstance;
class InventoryIterator;
class FileAdapter;
class StockItem;

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
     * @brief Uses the Adapter to load inventory from a file.
     * @param adapter The file reader adapter to use.
     * @param filePath The path to the file.
     */
    void loadFromFile(FileAdapter* adapter, std::string filePath);

    void saveToFile(FileAdapter* adapter, std::string filePath);

    // Friend class needed for iterator implementation
    friend class ConcreteInventoryIterator;

private:
    std::vector<StockItem*> items; ///< The underlying data structure.
};

#endif // INVENTORY_H