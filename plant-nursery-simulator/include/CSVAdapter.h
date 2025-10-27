#ifndef CSV_ADAPTER_H
#define CSV_ADAPTER_H

#include "FileAdapter.h"
#include <string>
#include <memory>

// Forward declarations
class Inventory;
class CSVReaderWriter;

/**
 * @file CSVAdapter.h
 * @brief 'Adapter' class that adapts CSVReaderWriter to FileAdapter. (FR9)
 */
class CSVAdapter : public FileAdapter {
public:
    CSVAdapter();
    ~CSVAdapter() override = default;

    void loadInventory(std::string filePath, Inventory* inventory) override;
    void saveInventory(std::string filePath, Inventory* inventory) override;

private:
    std::unique_ptr<CSVReaderWriter> csvReader; ///< The wrapped 'Adaptee'.
};

#endif // CSV_ADAPTER_H
