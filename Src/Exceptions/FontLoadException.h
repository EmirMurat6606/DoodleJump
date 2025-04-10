/********************************************************************************************
 * @file FontLoadException.h
 * @brief Handles font loading exceptions
 * @namespace exceptions
 ********************************************************************************************/

#ifndef FONTLOADEXCEPTION_H
#define FONTLOADEXCEPTION_H

#include "Exception.h"
#include <iostream>

namespace exceptions {
class FontLoadException : public Exception {
public:
    /**
     * Constructor of the FontLoadException class
     * @param filename font that failed to load
     */
    explicit FontLoadException(const std::string& filename) : Exception("Failed to load font: " + filename) {}

    /**
     * Constructor of the FontLoadException class
     * @param message error message
     * @param context error context for saving error code
     */
    explicit FontLoadException(const std::string& message, const std::string& context)
        : Exception(" Font Error: " + message, context) {}

    /**
     * Logs the error message
     * @param filename font that failed to open
     */
    static void fontNotFoundError(const std::string& filename) {
        std::cerr << "FontLoadException: Could not open font " << filename << std::endl;
    }
};

} // namespace exceptions
#endif // FONTLOADEXCEPTION_H
