#include "../include/CSVReaderWriter.h"
#include "../include/StockItem.h" // Needed for writing
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

CSVReaderWriter::CSVReaderWriter() {}

/**
 * @brief Reads data from a CSV file.
 * @param filePath Path to the file.
 * @return Vector of pairs (ItemName, Price). Handles basic parsing errors.
 */
std::vector<std::pair<std::string, double>> CSVReaderWriter::readCsv(const std::string& filePath) {
    std::vector<std::pair<std::string, double>> data;
    std::ifstream inputFile(filePath);
    std::string line;
    int lineNumber = 0;

    if (!inputFile.is_open()) {
        std::cerr << "[CSVReaderWriter] Error: Could not open file for reading: " << filePath << std::endl;
        return data; // Return empty vector on error
    }

    while (std::getline(inputFile, line)) {
        lineNumber++;
        std::stringstream ss(line);
        std::string segment;
        std::vector<std::string> fields;

        // Split line by comma
        while (std::getline(ss, segment, ',')) {
            fields.push_back(segment);
        }

        // Basic validation: Check for exactly two fields
        if (fields.size() == 2) {
            std::string name = fields[0];
            double price;
            try {
                // Try to convert the second field to a double
                price = std::stod(fields[1]);
                data.push_back({name, price});
            } catch (const std::invalid_argument& e) {
                std::cerr << "[CSVReaderWriter] Warning: Invalid price format on line " 
                          << lineNumber << " in file " << filePath << ". Skipping row: " << line << std::endl;
            } catch (const std::out_of_range& e) {
                 std::cerr << "[CSVReaderWriter] Warning: Price out of range on line " 
                          << lineNumber << " in file " << filePath << ". Skipping row: " << line << std::endl;
            }
        } else if (!line.empty()) { // Only warn if it's not just an empty line
            std::cerr << "[CSVReaderWriter] Warning: Malformed line " << lineNumber 
                      << " in file " << filePath << ". Expected 2 fields, got " 
                      << fields.size() << ". Skipping row: " << line << std::endl;
        }
    }

    inputFile.close();
    return data;
}

/**
 * @brief Writes inventory data to a CSV file.
 * @param filePath Path to the file.
 * @param items Vector of StockItem pointers to write.
 * @return true if successful, false otherwise.
 */
bool CSVReaderWriter::writeDataToCSV(const std::string& filePath, const std::vector<StockItem*>& items) {
    std::ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        std::cerr << "[CSVReaderWriter] Error: Could not open file for writing: " << filePath << std::endl;
        return false;
    }

    // Optional: Write header
    // outputFile << "ItemName,Price\n";

    for (const StockItem* item : items) {
        if (item != nullptr) {
            // Write "ItemName,Price"
            outputFile << item->getname() << "," << item->getPrice() << "\n";
        }
    }

    outputFile.close();
    // Check if writing failed
     if (!outputFile) {
        std::cerr << "[CSVReaderWriter] Error: Failed to write data to file: " << filePath << std::endl;
        return false; 
    }
    return true;
}
