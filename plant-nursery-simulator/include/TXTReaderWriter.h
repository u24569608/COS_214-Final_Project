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
    TXTReaderWriter();
    // Returns lines read, handles basic errors
    std::vector<std::string> readDataFromTxt(const std::string& filePath); 
    // Takes data to write, returns true on success
    bool writeDataToTxt(const std::string& filePath, const std::vector<StockItem*>& items); 
};

#endif // TXT_READER_WRITER_H
