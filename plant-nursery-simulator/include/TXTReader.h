#ifndef TXT_READER_H
#define TXT_READER_H

#include <vector>
#include <string>

/**
 * @file TXTReader.h
 * @brief The 'Adaptee' class for reading TXT files.
 * @details This is the incompatible interface.
 */
class TXTReader {
public:
    TXTReader();
    std::vector<std::string> readDataFromTxt(std::string filePath);
};

#endif // TXT_READER_H