/**************************************************************************
 * @file FontManager.h
 * @brief Loads and stores the fonts for the game and is a central access point for all fonts
 * @namespace assetManager
 **************************************************************************/

#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <unordered_map>

namespace assetManager {
class FontManager {

    /**
     * Map that stores all the fonts defined by a string key
     */
    std::unordered_map<std::string, std::shared_ptr<sf::Font>> fonts;

    /**
     * Constructor of the FontManager class
     */
    FontManager();

    /**
     * Default destructor of the FontManager class
     */
    ~FontManager() = default;

    /**
     * Boolean that ensures manager is initialized before call
     */
    static bool initialized;

public:
    /**
     * Function that returns the unique instance of the FontManager class
     */
    static FontManager& getInstance();

    /**
     * Eager initialization of the FontManager
     * \n when setting up the game
     */
    static void initialize();

    /**
     * Explicitly deleted copy constructor
     */
    FontManager(const FontManager&) = delete;

    /**
     * Explicitly deleted copy assignment operator
     */
    FontManager& operator=(const FontManager&) = delete;

    /**
     * Getter for a specific font
     * @param font_name the name of the font
     * @return a shared pointer to the font
     */
    std::shared_ptr<sf::Font> getFont(const std::string& font_name);
};
} // namespace assetManager

#endif // FONTMANAGER_H
