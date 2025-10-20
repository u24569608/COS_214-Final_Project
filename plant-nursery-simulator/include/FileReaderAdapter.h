#ifndef FILE_READER_ADAPTER_H
#define FILE_READER_ADAPTER_H

#include <string>

// Forward declaration to avoid circular include
class Inventory; 

/**
 * @file FileReaderAdapter.h
 * @brief The 'Target' interface for the Adapter pattern. (FR8)
 */
class FileReaderAdapter {
public:
    virtual ~FileReaderAdapter();
    /**
     * @brief Loads plant data from a file into inventory.
     * @param filePath The path to the data file.
     * @param inventory A pointer to the inventory to populate.
     */
    virtual void loadInventory(std::string filePath, Inventory* inventory) = 0;
};

#endif // FILE_READER_ADAPTER_H