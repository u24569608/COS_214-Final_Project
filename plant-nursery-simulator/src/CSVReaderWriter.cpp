/**
 * @file CSVReaderWriter.cpp
 * @brief Implements the CSVReaderWriter behaviour defined in the corresponding header.
 */

#include "../include/CSVReaderWriter.h"
#include "../include/StockItem.h" // Needed for writing
#include "../include/PlantInstance.h"
#include "../include/PlantState.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

CSVReaderWriter::CSVReaderWriter() {}

/**
 * @brief Reads data from a CSV file using the structured Item/Plant format.
 * @param filePath Path to the file.
 * @return Vector of raw field rows for further processing.
 */
std::vector<std::vector<std::string>> CSVReaderWriter::readCsv(const std::string& filePath) {
    std::vector<std::vector<std::string>> data;
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

        if (!line.empty()) { // Only warn if it's not just an empty line
            data.push_back(fields);
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

    for (const StockItem* item : items) {
        if (item == nullptr) {
            continue;
        }
        const PlantInstance* plant = item->getplant();
        if (plant != nullptr) {
            const PlantState* state = plant->getState();
            const std::string stateName = state ? state->getName() : "Seed";
            outputFile << "Plant," << item->getname() << "," << item->getPrice() << "," << stateName << "\n";
        } else {
            outputFile << "Item," << item->getname() << "," << item->getPrice() << "\n";
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
