#ifndef CSV_ADAPTER_H
#define CSV_ADAPTER_H

#include "FileAdapter.h"
#include "CSVReaderWriter.h"
#include <string>

// Forward declaration
class Inventory;

/**
 * @file CSVAdapter.h
 * @brief 'Adapter' class that adapts CSVReaderWriter to FileAdapter. (FR9)
 */
class CSVAdapter : public FileAdapter {
public:
    /**
     * @brief Creates a CSV-backed file adapter with its own reader/writer utility.
     */
    CSVAdapter();
    ~CSVAdapter() override = default;

    /**
     * @brief Populates the inventory state from a comma-separated file.
     * @param filePath Path to the CSV file to open.
     * @param inventory Target inventory instance to hydrate.
     */
    void loadInventory(std::string filePath, Inventory* inventory) override;

    /**
     * @brief Serialises the inventory contents to a CSV file.
     * @param filePath Destination file path.
     * @param inventory Inventory instance whose state should be exported.
     */
    void saveInventory(std::string filePath, Inventory* inventory) override;

private:
    CSVReaderWriter csvReader; ///< CSV helper used to read/write stock data.
};

#endif // CSV_ADAPTER_H
