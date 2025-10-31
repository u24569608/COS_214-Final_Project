#ifndef TXT_ADAPTER_H
#define TXT_ADAPTER_H

#include "FileAdapter.h"
#include "TXTReaderWriter.h"
#include <string>

// Forward declaration
class Inventory;

/**
 * @file TXTAdapter.h
 * @brief 'Adapter' class that adapts TXTReaderWriter to FileAdapter. (FR9)
 */
class TXTAdapter : public FileAdapter {
public:
    /**
     * @brief Constructs a TXT adapter with its own reader/writer instance.
     */
    TXTAdapter();
    ~TXTAdapter() override = default;

    /**
     * @brief Loads inventory data from a plain-text file.
     * @param filePath Location of the source file.
     * @param inventory Target inventory to populate.
     */
    void loadInventory(std::string filePath, Inventory* inventory) override;

    /**
     * @brief Saves inventory contents to a plain-text file.
     * @param filePath Destination file path.
     * @param inventory Inventory whose data should be exported.
     */
    void saveInventory(std::string filePath, Inventory* inventory) override;

private:
    TXTReaderWriter txtReader; ///< TXT helper used to read/write stock data.
};

#endif // TXT_ADAPTER_H
