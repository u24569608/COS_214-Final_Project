#ifndef TXT_ADAPTER_H
#define TXT_ADAPTER_H

#include "FileAdapter.h"
#include <string>

// Forward declarations
class Inventory;
class TXTReaderWriter;

/**
 * @file TXTAdapter.h
 * @brief 'Adapter' class that adapts TXTReaderWriter to FileAdapter. (FR9)
 */
class TXTAdapter : public FileAdapter {
public:
    TXTAdapter();
    ~TXTAdapter();

    void loadInventory(std::string filePath, Inventory* inventory) override;
    void saveInventory(std::string filePath, Inventory* inventory) override;

private:
    TXTReaderWriter* txtReader; ///< The wrapped 'Adaptee'.
};

#endif // TXT_ADAPTER_H