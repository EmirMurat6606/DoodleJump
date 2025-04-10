//
// Created by emir on 12/14/24.
//

#include "FontManager.h"
#include "../Exceptions/FontLoadException.h"
#include "../Exceptions/InitializeException.h"

bool assetManager::FontManager::initialized = false;

assetManager::FontManager::FontManager() {
    auto loadFont = [](const std::string& file) -> std::shared_ptr<sf::Font> {
        auto font = std::make_shared<sf::Font>();
        if (!font->loadFromFile(file)) {
            throw exceptions::FontLoadException(file);
        }
        return font;
    };

    fonts["doodle_jump"] = loadFont("../Assets/Fonts/DoodleJump.ttf");
}

assetManager::FontManager& assetManager::FontManager::getInstance() {
    if (!initialized) {
        throw exceptions::InitTextureManagerException();
    }
    static FontManager instance;
    return instance;
}

void assetManager::FontManager::initialize() {
    initialized = true;
    (void)getInstance();
}

std::shared_ptr<sf::Font> assetManager::FontManager::getFont(const std::string& font_name) {
    return fonts.at(font_name);
}
