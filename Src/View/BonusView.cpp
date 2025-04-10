//
// Created by emir on 11/10/24.
//

#include "BonusView.h"
#include "../AssetManager/TextureManager.h"
#include "../Configs/GameConfig.h"
#include "../Model/Bonus.h"

gameView::BonusView::BonusView(const std::weak_ptr<sf::RenderWindow>& game_window) : EntityView(game_window) {}

gameView::JetpackBonusView::JetpackBonusView(const std::weak_ptr<sf::RenderWindow>& game_window)
    : BonusView(game_window) {
    entity_sprite.setTexture(*assetManager::TextureManager::getInstance().getTexture("jetpack"));
    auto [x, y] = assetManager::TextureManager::getInstance().scaleTexture(
        "jetpack", configs::GameConfig::JETPACK_WIDTH, configs::GameConfig::JETPACK_HEIGHT);
    // Apply the scale to the sprite
    entity_sprite.setScale(x, y);
}

gameView::SpringBonusView::SpringBonusView(const std::weak_ptr<sf::RenderWindow>& game_window)
    : BonusView(game_window) {
    entity_sprite.setTexture(*assetManager::TextureManager::getInstance().getTexture("spring"));
    auto [x, y] = assetManager::TextureManager::getInstance().scaleTexture("spring", configs::GameConfig::SPRING_WIDTH,
                                                                           configs::GameConfig::SPRING_HEIGHT);
    // Apply the scale to the sprite
    entity_sprite.setScale(x, y);
}
