//
// Created by emir on 12/2/24.
//

#include "BGTileGenerator.h"
#include "../Model/AEntityFactory.h"
#include "../Model/BGTile.h"

gameControl::BGTileGenerator::BGTileGenerator(const std::shared_ptr<gameModel::AEntityFactory>& factory)
    : entity_factory(factory) {}

void gameControl::BGTileGenerator::generate(std::vector<std::shared_ptr<gameModel::BGTile>>& tiles) const {

    // Constant offset to prevent gaps between tiles
    constexpr double offset = 0.0;

    // If the vector is empty, generate the first row of tiles
    //--------------------------------------------------------
    if (tiles.empty()) {
        tiles.reserve(configs::GameConfig::TILE_COUNT_X *
                      (configs::GameConfig::TILE_COUNT_Y + 1)); // #tiles doesn't change
        for (int i = 0; i < configs::GameConfig::TILE_COUNT_Y; ++i) {
            for (int j = 0; j < configs::GameConfig::TILE_COUNT_X; ++j) {
                tiles.push_back(
                    entity_factory->createBGTile(j * gameModel::BGTile::tileWidth, i * gameModel::BGTile::tileHeight));
            }
        }
        return;
    }

    // If the vector contains tiles, generate new tiles
    //--------------------------------------------------------
    double currentMax = 0.0;
    if (tiles.back()->y_Max() > currentMax) {
        currentMax = tiles.back()->y_Max();
    }
    if (currentMax < configs::GameConfig::VIEW_HEIGHT + offset) {
        for (int i = 0; i < configs::GameConfig::TILE_COUNT_X; ++i) {
            tiles.push_back(entity_factory->createBGTile(gameModel::BGTile::tileWidth * i, currentMax));
        }
    }
}
