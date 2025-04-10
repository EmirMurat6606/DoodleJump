/*****************************************************************************************
 * @file Game.h
 * @brief This file contains the declaration of the Game class
 * /n The Game class is responsible for setting up and running the main loop of the game
 * @namespace gameView
 *****************************************************************************************/

#ifndef GAME_SFML_H
#define GAME_SFML_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace events {
class EventHandler;
}

namespace gameControl {
class World;
}

namespace gameModel {
class Score;
}

/**
 * @enum GameState Represents the different states of the game
 * ---------------------------------------------
 * \n StartMenu - start menu state
 * \n Playing - playing state
 * \n GameOverMenu - game over menu state
 */
enum GameState { StartMenu, Playing, GameOverMenu };

namespace gameView {
class Game {
    /**
     * The main game window of the game
     * \n This window is created using the SFML library
     * \n This window can be shared with entities of the game to change the view
     */
    std::shared_ptr<sf::RenderWindow> window;

    /**
     * The unique world of the game
     */
    std::unique_ptr<gameControl::World> world;

    /**
     * The event handler of the game
     */
    std::unique_ptr<events::EventHandler> eventHandler;

    /**
     * Shared pointer to the score of the game
     */
    std::shared_ptr<gameModel::Score> score;

    /**
     * Boolean variable that indicates if the main window is running
     */
    bool isRunning;

    /**
     * Boolean variable that indicates if the game has started
     */
    bool gameStarted = false;

    /**
     * The current state of the game
     * \n Initially set on start menu
     */
    GameState currentState = StartMenu;

public:
    /**
     * Constructor of the game class
     * \n Creates the game window and initializes the game
     */
    Game();

    /**
     * Destructor of the game class
     */
    ~Game();

    /**
     * Explicitly deleted copy constructor
     * \n No copy is allowed
     */
    Game(const Game&) = delete;

    /**
     * Explicitly deleted copy assignment operator
     * \n No copy assignment is allowed
     */
    Game& operator=(const Game&) = delete;

    /**
     * Function that runs the game
     */
    void run();

    // GUI elements
    //--------------
private:
    /**
     * Sprite used for the game over menu
     */
    sf::Sprite gameOverSprite;

    /**
     * Sprite used for the game menu
     */
    sf::Sprite gameMenuSprite;

    /**
     * Text used for the game score display
     */
    sf::Text scoreText;

    /**
     * Text used for the high score display
     */
    sf::Text highScoreText;

private:
    /**
     * Function that resets the game to the initial state
     */
    void reset();

    /**
     * Function that updates the game state
     */
    void updateGame(double deltaTime) const;

    /**
     * Function that initializes the graphics of the game
     */
    void initializeGraphics();

    /**
     * Function that creates and displays the start menu
     */
    void displayStartMenu();

    /**
     * Function that creates and displays the game over menu
     */
    void displayGameOverMenu();
};
} // namespace gameView
#endif // GAME_SFML_H
