/*****************************************************************************************
 * @file Exception.h
 * @brief File that contains the declaration of the Exception class
 * @namespace exceptions
 *****************************************************************************************/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <sstream>
#include <string>
#include <utility>

namespace exceptions {

class Exception : public std::exception {
    /**
     * Error message
     */
    std::string errorMessage;

public:
    /**
     * Default constructor of the Exception class
     */
    Exception() = default;

    /**
     * Default destructor of the Exception class
     */
    ~Exception() override = default;

    /**
     * Constructor of the Exception class
     * @param exception error message
     */
    explicit Exception(std::string exception) : errorMessage(std::move(exception)) {}

    /**
     * Constructor of the Exception class
     * @param message error message
     * @param context error context for saving error code
     */
    Exception(const std::string& message, const std::string& context) {
        std::stringstream ss;
        ss << message << " Context: " << context;
        errorMessage = ss.str();
    }

    /**
     * Function that returns a more detailed error message
     * @return error message
     */
    const char* what() const noexcept override { return errorMessage.c_str(); }
};
} // namespace exceptions

#endif // EXCEPTION_H
