//
// Created by emir on 11/29/24.
//

#include "TextureManager.h"
#include "../Configs/GameConfig.h"
#include "../Exceptions/InitializeException.h"
#include "../Exceptions/TextureLoadException.h"
#include "../Model/Camera.h"

bool assetManager::TextureManager::initialized = false;

assetManager::TextureManager::TextureManager() {
    auto loadTexture = [](const std::string& file) -> std::shared_ptr<sf::Texture> {
        auto texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(file)) {
            throw exceptions::TextureLoadException(file);
        }
        return texture;
    };
    // Load all the textures in the game
    textures["game_menu"] = loadTexture("../Assets/Textures/game_menu.png");
    textures["player"] = loadTexture("../Assets/Textures/doodle_space.png");
    textures["horizontal_platform"] = loadTexture("../Assets/Textures/blue_platform.png");
    textures["vertical_platform"] = loadTexture("../Assets/Textures/yellow_platform.png");
    textures["static_platform"] = loadTexture("../Assets/Textures/green_platform.png");
    textures["temporary_platform"] = loadTexture("../Assets/Textures/white_platform.png");
    textures["jetpack"] = loadTexture("../Assets/Textures/jetpack.png");
    textures["spring"] = loadTexture("../Assets/Textures/spring.png");
    textures["background"] = loadTexture("../Assets/Textures/background.png");
    textures["black_hole"] = loadTexture("../Assets/Textures/black_hole.png");
    textures["game_over"] = loadTexture("../Assets/Textures/game_over.png");
}

assetManager::TextureManager& assetManager::TextureManager::getInstance() {
    if (!initialized) {
        throw exceptions::InitTextureManagerException();
    }
    static TextureManager instance;
    return instance;
}

void assetManager::TextureManager::initialize() {
    initialized = true;
    (void)getInstance();
}

std::shared_ptr<sf::Texture> assetManager::TextureManager::getTexture(const std::string& textureName) const {
    return textures.at(textureName);
}

std::pair<float, float> assetManager::TextureManager::scaleTexture(const std::string& textureName,
                                                                   const double entityWidth,
                                                                   const double entityHeight) const {
    const auto& texture = textures.at(textureName);
    const float scaleX = static_cast<float>((entityWidth * configs::GameConfig::RES_WIDTH) /
                                            (configs::GameConfig::VIEW_WIDTH * texture->getSize().x));
    const float scaleY = static_cast<float>((entityHeight * configs::GameConfig::RES_HEIGHT) /
                                            (configs::GameConfig::VIEW_HEIGHT * texture->getSize().y));
    return {scaleX, scaleY};
}
