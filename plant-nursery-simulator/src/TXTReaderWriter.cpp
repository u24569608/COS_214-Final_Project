#include "../include/TXTReaderWriter.h"
#include "../include/StockItem.h" // Needed for writing
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

TXTReaderWriter::TXTReaderWriter() {}

/**
 * @brief Reads data from a space-separated TXT file.
 * @param filePath Path to the file.
 * @return Vector of strings, each string is one line from the file.
 * Returns an empty vector if the file cannot be opened.
 */
std::vector<std::string> TXTReaderWriter::readDataFromTxt(const std::string& filePath) {
    std::vector<std::string> lines;
    std::ifstream inputFile(filePath);
    std::string line;

    if (!inputFile.is_open()) {
        std::cerr << "[TXTReaderWriter] Error: Could not open file for reading: " << filePath << std::endl;
        return lines; // Return empty vector on error
    }

    while (std::getline(inputFile, line)) {
        if (!line.empty()) { // Skip empty lines
            lines.push_back(line);
        }
    }

    inputFile.close();
    return lines;
}

/**
 * @brief Writes inventory data to a TXT file.
 * @param filePath Path to the file.
 * @param items Vector of StockItem pointers to write.
 * @return true if successful, false otherwise.
 */
bool TXTReaderWriter::writeDataToTxt(const std::string& filePath, const std::vector<StockItem*>& items) {
    std::ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        std::cerr << "[TXTReaderWriter] Error: Could not open file for writing: " << filePath << std::endl;
        return false;
    }

    for (const StockItem* item : items) {
        if (item != nullptr) {
            // Write "ItemName Price"
            outputFile << item->getname() << " " << item->getPrice() << "\n";
        }
    }

    outputFile.close();
    // Check if writing failed (e.g., disk full)
    if (!outputFile) {
        std::cerr << "[TXTReaderWriter] Error: Failed to write data to file: " << filePath << std::endl;
        return false; 
    }
    
    return true;
}
