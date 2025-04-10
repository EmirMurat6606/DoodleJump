/********************************************************************************************
 * @file InitializeException.h
 * @brief Handles exceptions when a class is not initialized
 * @namespace exceptions
 ********************************************************************************************/

#ifndef INITIALIZEEXCEPTION_H
#define INITIALIZEEXCEPTION_H

#include "Exception.h"
namespace exceptions {
class InitializeException : public Exception {
public:
    /**
     * Constructor of the InitializeException class
     * @param className name of the class that is not initialized
     * @param context context of the error
     */
    explicit InitializeException(const std::string& className, const std::string& context = "")
        : Exception("Not initialized: " + className + " must be initialized before use." +
                    (context.empty() ? "" : " Context: " + context)) {}
};
class InitTextureManagerException : public InitializeException {
public:
    /**
     * Constructor of the InitTextureManagerException class
     */
    explicit InitTextureManagerException()
        : InitializeException("TextureManager", "gameView::TextureManager::getInstance()") {}
};

} // namespace exceptions

#endif // INITIALIZEEXCEPTION_H
