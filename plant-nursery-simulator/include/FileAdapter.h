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
    /**
     * @brief Guarantees derived adapters release resources correctly.
     */
    virtual ~FileAdapter();
    /**
     * @brief Loads plant data from a file into inventory.
     * @param filePath The path to the data file.
     * @param inventory A pointer to the inventory to populate.
     */
    virtual void loadInventory(std::string filePath, Inventory* inventory) = 0;

    /**
     * @brief Saves plant data from the inventory into storage.
     * @param filePath Destination data file path.
     * @param inventory Pointer to the inventory supplying data.
     */
    virtual void saveInventory(std::string filePath, Inventory* inventory) = 0;
};

#endif // FILE_ADAPTER_H
