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
    /**
     * @brief Constructs a CSV utility with default parsing configuration.
     */
    CSVReaderWriter();

    /**
     * @brief Loads and tokenises comma-separated values from disk.
     * @param filePath Path to the CSV file to read.
     * @return Matrix of string tokens, one vector per row.
     */
    std::vector<std::vector<std::string>> readCsv(const std::string& filePath);

    /**
     * @brief Persists stock item data as comma-separated rows.
     * @param filePath Destination file path.
     * @param items Collection of stock items to encode.
     * @return True when all data is written successfully.
     */
    bool writeDataToCSV(const std::string& filePath, const std::vector<StockItem*>& items);
};

#endif // CSV_READER_WRITER_H
