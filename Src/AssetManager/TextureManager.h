/**************************************************************************************************
 * @file TextureManager.h
 * @brief Loads and stores the textures for the game and is a central access point for all textures
 * @namespace assetManager
 **************************************************************************************************/

#ifndef TEXTUREMANAGER_SFML_H
#define TEXTUREMANAGER_SFML_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>

namespace assetManager {
class TextureManager {

    /**
     * Map that stores all the textures defined by a string key
     */
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;

    /**
     * Constructor of the TextureManager class
     */
    TextureManager();

    /**
     * Default destructor of the TextureManager class
     */
    ~TextureManager() = default;

    /**
     * Boolean that ensures manager is initialized before call
     */
    static bool initialized;

public:
    /**
     * Function that returns the unique instance of the TextureManager class
     */
    static TextureManager& getInstance();

    /**
     * Eager initialization of the TextureManager
     * \n when setting up the game
     */
    static void initialize();

    /**
     * Explicitly deleted copy constructor
     */
    TextureManager(const TextureManager&) = delete;

    /**
     * Explicitly deleted copy assignment operator
     */
    TextureManager& operator=(const TextureManager&) = delete;

    /**
     * Getter for a specific texture
     * @param textureName The name of the texture
     * @return Shared pointer to the appropriate texture
     */
    std::shared_ptr<sf::Texture> getTexture(const std::string& textureName) const;

    /**
     * Scale the texture based on texture size and entity size
     */
    std::pair<float, float> scaleTexture(const std::string& textureName, double entityWidth, double entityHeight) const;
};
} // namespace assetManager

#endif // TEXTUREMANAGER_SFML_H
