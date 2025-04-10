//
// Created by emir on 11/10/24.
//

#include "BGTileView.h"
#include "../AssetManager/TextureManager.h"
#include "../Model/BGTile.h"

gameView::BGTileView::BGTileView(const std::weak_ptr<sf::RenderWindow>& game_window) : EntityView(game_window) {
    entity_sprite.setTexture(*assetManager::TextureManager::getInstance().getTexture("background"));
    auto [x, y] = assetManager::TextureManager::getInstance().scaleTexture("background", gameModel::BGTile::tileWidth,
                                                                           gameModel::BGTile::tileHeight);
    // Apply the scale to the sprite
    entity_sprite.setScale(x, y);
}
