//
// Created by emir on 12/13/24.
//

#include "ObstacleView.h"
#include "../AssetManager/TextureManager.h"
#include "../Configs/GameConfig.h"

gameView::ObstacleView::ObstacleView(const std::weak_ptr<sf::RenderWindow>& game_window) : EntityView(game_window) {}

gameView::BlackHoleObstacleView::BlackHoleObstacleView(const std::weak_ptr<sf::RenderWindow>& game_window)
    : ObstacleView(game_window) {
    entity_sprite.setTexture(*assetManager::TextureManager::getInstance().getTexture("black_hole"));
    auto [x, y] = assetManager::TextureManager::getInstance().scaleTexture(
        "black_hole", configs::GameConfig::BLACK_HOLE_WIDTH, configs::GameConfig::BLACK_HOLE_HEIGHT);
    // Apply the scale to the sprite
    entity_sprite.setScale(x, y);
}
