#ifndef CSV_READER_WRITER_H
#define CSV_READER_WRITER_H

#include <vector>
#include <string>
#include <utility> // For std::pair

/**
 * @file CSVReaderWriter.h
 * @brief The 'Adaptee' class for reading CSV files.
 * @details This is another incompatible interface.
 */
class CSVReaderWriter {
public:
    CSVReaderWriter();
    std::vector<std::pair<std::string, int>> readCsv(std::string filePath);
    void writeDataToCSV();
};

#endif // CSV_READER_WRITER_H