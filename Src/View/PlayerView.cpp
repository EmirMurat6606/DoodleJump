//
// Created by emir on 11/10/24.
//

#include "PlayerView.h"
#include "../AssetManager/TextureManager.h"
#include "../Configs/GameConfig.h"
#include "../Model/Player.h"

gameView::PlayerView::PlayerView(const std::weak_ptr<sf::RenderWindow>& game_window) : EntityView(game_window) {
    // Set the texture of the player
    entity_sprite.setTexture(*assetManager::TextureManager::getInstance().getTexture("player"));
    auto [x, y] = assetManager::TextureManager::getInstance().scaleTexture("player", configs::GameConfig::PLAYER_WIDTH,
                                                                           configs::GameConfig::PLAYER_HEIGHT);
    // Apply the scale to the sprite
    entity_sprite.setScale(x, y);
}
