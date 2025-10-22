#ifndef FILE_ADAPTER_H
#define FILE_ADAPTER_H

#include <string>

// Forward declaration to avoid circular include
class Inventory; 

/**
 * @file FileAdapter.h
 * @brief The 'Target' interface for the Adapter pattern. (FR8)
 */
class FileAdapter {
public:
    virtual ~FileAdapter();
    /**
     * @brief Loads plant data from a file into inventory.
     * @param filePath The path to the data file.
     * @param inventory A pointer to the inventory to populate.
     */
    virtual void loadInventory(std::string filePath, Inventory* inventory) = 0;

       /**
     * @brief saves plant data from a inventory into file.
     * @param filePath The path to the data file.
     * @param inventory A pointer to the inventory to populate.
     */
    virtual void saveInventory(std::string filePath, Inventory* inventory) = 0;
};

#endif // FILE_ADAPTER_H