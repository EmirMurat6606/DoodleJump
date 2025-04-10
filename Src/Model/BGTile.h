/*****************************************************************************************
 * @file: BGTile.h
 * @brief The BGTile class represents the background tiles in the game.
 * @namespace gameModel
 *****************************************************************************************/

#ifndef DOODLE_GAME_BGTILE_H
#define DOODLE_GAME_BGTILE_H

#include "../Configs/GameConfig.h"
#include "Entity.h"

namespace gameModel {

class BGTile : public Entity {

public:
    /**
     * Width of the tile
     * \n Calculated based on the view width and the number of tiles in the x direction
     */
    static constexpr double tileWidth = configs::GameConfig::VIEW_WIDTH / configs::GameConfig::TILE_COUNT_X;

    /**
     * Height of the tile
     * \n Calculated based on the view height and the number of tiles in the y direction
     */
    static constexpr double tileHeight = configs::GameConfig::VIEW_HEIGHT / configs::GameConfig::TILE_COUNT_Y;

    /**
     * Constructor of the BGTile class
     * @param x_location initial x location of the BGTile
     * @param y_location initial y location of the BGTile
     */
    BGTile(double x_location, double y_location);

    /**
     * Destructor of the BGTile class
     */
    ~BGTile() override = default;
};

} // namespace gameModel
#endif // DOODLE_GAME_BGTILE_H
