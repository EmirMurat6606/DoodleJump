/*****************************************************************************************
 * @file PlayerView.h
 * @brief This file contains the declaration of the PlayerGUI class
 * @namespace gameView
 *****************************************************************************************/

#ifndef PLAYERGUI_SFML_H
#define PLAYERGUI_SFML_H
#include "EntityView.h"

namespace gameView {
class PlayerView : public EntityView {

public:
    /**
     * Constructor of the PlayerView class
     * @param game_window weak pointer to the main game window
     */
    explicit PlayerView(const std::weak_ptr<sf::RenderWindow>& game_window);
};
} // namespace gameView

#endif // PLAYERGUI_SFML_H
