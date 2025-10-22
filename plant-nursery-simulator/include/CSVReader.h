#ifndef CSV_READER_H
#define CSV_READER_H

#include <vector>
#include <string>
#include <utility> // For std::pair

/**
 * @file CSVReader.h
 * @brief The 'Adaptee' class for reading CSV files.
 * @details This is another incompatible interface.
 */
class CSVReader {
public:
    CSVReader();
    std::vector<std::pair<std::string, int>> readCsv(std::string filePath);
};

#endif // CSV_READER_H