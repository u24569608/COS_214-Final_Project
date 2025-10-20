#ifndef TXT_FILE_READER_ADAPTER_H
#define TXT_FILE_READER_ADAPTER_H

#include "FileReaderAdapter.h"
#include <string>

// Forward declarations
class Inventory;
class TXTReader;

/**
 * @file TxtFileReaderAdapter.h
 * @brief 'Adapter' class that adapts TXTReader to FileReaderAdapter. (FR9)
 */
class TxtFileReaderAdapter : public FileReaderAdapter {
public:
    TxtFileReaderAdapter();
    ~TxtFileReaderAdapter();

    void loadInventory(std::string filePath, Inventory* inventory) override;

private:
    TXTReader* txtReader; ///< The wrapped 'Adaptee'.
};

#endif // TXT_FILE_READER_ADAPTER_H