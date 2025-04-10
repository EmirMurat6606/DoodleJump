/**************************************************************************
 * @file TextureLoadException.h
 * @brief Handles texture loading exceptions
 * @namespace exceptions
 **************************************************************************/

#ifndef TEXTURELOADEXCEPTION_H
#define TEXTURELOADEXCEPTION_H

#include "Exception.h"

namespace exceptions {
class TextureLoadException : public Exception {
public:
    /**
     * Constructor of the TextureLoadException class
     * @param texture_path texture that failed to load
     */
    explicit TextureLoadException(const std::string& texture_path)
        : Exception("Failed to load texture: " + texture_path) {}

    /**
     * Constructor of the TextureLoadException class
     * @param message error message
     * @param context error context for saving error code
     */
    TextureLoadException(const std::string& message, const std::string& context)
        : Exception("Texture Error: " + message, context) {}
};

} // namespace exceptions

#endif // TEXTURELOADEXCEPTION_H
