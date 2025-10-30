#ifndef TXT_READER_WRITER_H
#define TXT_READER_WRITER_H

#include <vector>
#include <string>

// Forward declaration
class StockItem;

/**
 * @file TXTReaderWriter.h
 * @brief The 'Adaptee' class for reading/writing TXT files.
 */
class TXTReaderWriter {
public:
    /**
     * @brief Constructs a TXT utility with default parsing rules.
     */
    TXTReaderWriter();

    /**
     * @brief Reads a plain-text inventory file into memory.
     * @param filePath Path to the TXT file.
     * @return Collection of lines extracted from the file.
     */
    std::vector<std::string> readDataFromTxt(const std::string& filePath); 

    /**
     * @brief Writes stock item data to a plain-text file.
     * @param filePath Destination file path.
     * @param items Collection of stock items to serialise.
     * @return True when the write succeeds.
     */
    bool writeDataToTxt(const std::string& filePath, const std::vector<StockItem*>& items); 
};

#endif // TXT_READER_WRITER_H
