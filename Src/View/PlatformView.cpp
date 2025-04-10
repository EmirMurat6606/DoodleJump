//
// Created by emir on 11/10/24.
//

#include "PlatformView.h"
#include "../AssetManager/TextureManager.h"
#include "../Configs/GameConfig.h"
#include "../Model/Platform.h"

gameView::PlatformView::PlatformView(const std::weak_ptr<sf::RenderWindow>& game_window) : EntityView(game_window) {}

gameView::StaticPlatformView::StaticPlatformView(const std::weak_ptr<sf::RenderWindow>& game_window)
    : PlatformView(game_window) {
    entity_sprite.setTexture(*assetManager::TextureManager::getInstance().getTexture("static_platform"));
    auto [x, y] = assetManager::TextureManager::getInstance().scaleTexture(
        "static_platform", configs::GameConfig::PLATFORM_WIDTH, configs::GameConfig::PLATFORM_HEIGHT);
    // Apply the scale to the sprconfigs::GameConfig::PLATFORM_WIDTH, configs::GameConfig::PLAYER_HEIGHTite
    entity_sprite.setScale(x, y);
}

gameView::HorizontalPlatformView::HorizontalPlatformView(const std::weak_ptr<sf::RenderWindow>& game_window)
    : PlatformView(game_window) {
    entity_sprite.setTexture(*assetManager::TextureManager::getInstance().getTexture("horizontal_platform"));
    auto [x, y] = assetManager::TextureManager::getInstance().scaleTexture(
        "horizontal_platform", configs::GameConfig::PLATFORM_WIDTH, configs::GameConfig::PLATFORM_HEIGHT);
    // Apply the scale to the sprite
    entity_sprite.setScale(x, y);
}

gameView::VerticalPlatformView::VerticalPlatformView(const std::weak_ptr<sf::RenderWindow>& game_window)
    : PlatformView(game_window) {
    entity_sprite.setTexture(*assetManager::TextureManager::getInstance().getTexture("vertical_platform"));
    auto [x, y] = assetManager::TextureManager::getInstance().scaleTexture(
        "vertical_platform", configs::GameConfig::PLATFORM_WIDTH, configs::GameConfig::PLATFORM_HEIGHT);
    // Apply the scale to the sprite
    entity_sprite.setScale(x, y);
}

gameView::TemporaryPlatformView::TemporaryPlatformView(const std::weak_ptr<sf::RenderWindow>& game_window)
    : PlatformView(game_window) {
    entity_sprite.setTexture(*assetManager::TextureManager::getInstance().getTexture("temporary_platform"));
    auto [x, y] = assetManager::TextureManager::getInstance().scaleTexture(
        "temporary_platform", configs::GameConfig::PLATFORM_WIDTH, configs::GameConfig::PLATFORM_HEIGHT);
    // Apply the scale to the sprite
    entity_sprite.setScale(x, y);
}
