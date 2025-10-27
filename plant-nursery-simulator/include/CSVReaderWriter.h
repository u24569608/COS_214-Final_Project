#ifndef CSV_READER_WRITER_H
#define CSV_READER_WRITER_H

#include <vector>
#include <string>
#include <utility> // For std::pair

// Forward declaration
class StockItem;

/**
 * @file CSVReaderWriter.h
 * @brief The 'Adaptee' class for reading/writing CSV files.
 */
class CSVReaderWriter {
public:
    CSVReaderWriter();
    // Returns pairs read, handles basic errors
    std::vector<std::vector<std::string>> readCsv(const std::string& filePath);
    // Takes data to write, returns true on success
    bool writeDataToCSV(const std::string& filePath, const std::vector<StockItem*>& items);
};

#endif // CSV_READER_WRITER_H
