/******************************************************************************************
 * @file FileLoadException.h
 * @brief Handles file loading exceptions
 * @namespace exceptions
 *****************************************************************************************/

#ifndef FILELOADEXCEPTION_H
#define FILELOADEXCEPTION_H

#include <iostream>

#include "Exception.h"

namespace exceptions {
class FileLoadException : public Exception {
public:
    /**
     * Constructor of the FileLoadException class
     * @param file file that failed to load
     * @param context context of the error
     */
    explicit FileLoadException(const std::string& file, const std::string& context = "")
        : Exception("Error reading file: " + file + (context.empty() ? "" : " in context: " + context)) {}

    /**
     * Logs the error message
     * @param filename file that failed to open
     */
    static void fileNotOpened(const std::string& filename) {
        std::cerr << "FileLoadException: Could not open file " << filename << std::endl;
    }

    /**
     * Logs the error message
     * @param filename file that failed to read from
     */
    static void fileReadError(const std::string& filename) {
        std::cerr << "FileLoadException: Could not read from file " << filename << std::endl;
    }

    /**
     * Logs the error message
     * @param filename file that failed to write to
     */
    static void fileWriteError(const std::string& filename) {
        std::cerr << "FileLoadException: Could not write to file " << filename << std::endl;
        std::cerr << "!!! Possible loss of data !!!" << std::endl;
    }
};
} // namespace exceptions

#endif // FILELOADEXCEPTION_H
