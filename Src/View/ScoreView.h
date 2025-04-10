/*****************************************************************************************
 * @file ScoreView.h
 * @brief This file contains the declaration of the ScoreGUI class
 * @namespace gameView
 *****************************************************************************************/

#ifndef SCOREGUI_SFML_H
#define SCOREGUI_SFML_H

#include "../Model/Observer.h"
#include <SFML/Graphics.hpp>
#include <memory>

#include "../Model/Score.h"

namespace gameView {
class ScoreView : public gameModel::Observer<gameModel::Score> {

    /**
     * Font of the score
     */
    sf::Font font;

    /**
     * Text of the score
     */
    sf::Text scoreText;

    /**
     * Weak pointer to the game window
     */
    std::weak_ptr<sf::RenderWindow> game_window;

    /**
     * Color of the score text
     */
    sf::Color color = sf::Color(220, 255, 70);

    /**
     * Position of the score
     * \n Pixel coordinates
     */
    static constexpr std::pair<float, float> position = {10, 0};

public:
    /**
     * Constructor of the ScoreGUI class
     * @param game_window weak pointer to the main game window
     */
    explicit ScoreView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Draws the score on the screen
     */
    void draw() const;

    /**
     * Updates the score representation on the screen
     * @param score the score subject providing information
     */
    void update(const gameModel::Score& score) override;
};
} // namespace gameView

#endif // SCOREGUI_SFML_H
