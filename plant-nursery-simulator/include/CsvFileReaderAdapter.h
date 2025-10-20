#ifndef CSV_FILE_READER_ADAPTER_H
#define CSV_FILE_READER_ADAPTER_H

#include "FileReaderAdapter.h"
#include <string>

// Forward declarations
class Inventory;
class CSVReader;

/**
 * @file CsvFileReaderAdapter.h
 * @brief 'Adapter' class that adapts CSVReader to FileReaderAdapter. (FR9)
 */
class CsvFileReaderAdapter : public FileReaderAdapter {
public:
    CsvFileReaderAdapter();
    ~CsvFileReaderAdapter();

    void loadInventory(std::string filePath, Inventory* inventory) override;

private:
    CSVReader* csvReader; ///< The wrapped 'Adaptee'.
};

#endif // CSV_FILE_READER_ADAPTER_H