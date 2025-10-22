#ifndef TXT_READER_WRITER_H
#define TXT_READER_WRITER_H

#include <vector>
#include <string>

/**
 * @file TXTReaderWriter.h
 * @brief The 'Adaptee' class for reading TXT files.
 * @details This is the incompatible interface.
 */
class TXTReaderWriter {
public:
    TXTReaderWriter();
    std::vector<std::string> readDataFromTxt();
    void writeDataToTxt();
};

#endif // TXT_READER_WRITER_H