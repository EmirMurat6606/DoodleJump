/*****************************************************************************************
 * @file BGTileView.h
 * @brief This file contains the declaration of the BGTileGUI class
 * @namespace gameView
 *****************************************************************************************/

#ifndef BGTILEGUI_SFML_H
#define BGTILEGUI_SFML_H

#include "EntityView.h"

namespace gameView {
class BGTileView : public EntityView {

public:
    /**
     * Constructor of the BGTileView class
     * @param game_window weak pointer to the main game window
     */
    explicit BGTileView(const std::weak_ptr<sf::RenderWindow>& game_window);
};
} // namespace gameView

#endif // BGTILEGUI_SFML_H
