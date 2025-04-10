//
// Created by emir on 11/9/24.
//

#include "Game.h"
#include "../AssetManager/FontManager.h"
#include "../AssetManager/TextureManager.h"
#include "../Configs/GameConfig.h"
#include "../Control/World.h"
#include "../Events/EventHandler.h"
#include "../Events/KeyPressEvent.h"
#include "../Events/SpaceKeyEvent.h"
#include "../Events/WindowCloseEvent.h"
#include "../Model/Score.h"
#include "../Model/Stopwatch.h"
#include "CEntityFactory.h"

gameView::Game::Game()
    : window(std::make_shared<sf::RenderWindow>(
          sf::VideoMode(configs::GameConfig::RES_WIDTH, configs::GameConfig::RES_HEIGHT), "Doodle Jump")),
      isRunning(true) {

    // Load all the textures in the game
    assetManager::TextureManager::initialize();

    // Load all the fonts in the game
    assetManager::FontManager::initialize();

    window->setFramerateLimit(configs::GameConfig::FPS);

    // Initialize the eventhandler
    eventHandler = std::make_unique<events::EventHandler>(window);

    std::shared_ptr<gameModel::AEntityFactory> entity_factory = std::make_shared<CEntityFactory>(window);
    score = entity_factory->createScore();
    world = std::make_unique<gameControl::World>(entity_factory, score);

    // Initialize the game graphics
    initializeGraphics();
}

gameView::Game::~Game() { window->close(); }

void gameView::Game::reset() {
    score->reset();
    std::shared_ptr<gameModel::AEntityFactory> entity_factory = std::make_shared<CEntityFactory>(window);
    world.reset();
    world = std::make_unique<gameControl::World>(entity_factory, score);
}

void gameView::Game::updateGame(const double deltaTime) const {
    window->clear();
    world->update(deltaTime);
    window->display();
}

void gameView::Game::initializeGraphics() {
    // Initialize the score and high score text
    //-----------------------------------------
    const std::shared_ptr<sf::Font>& text_font = assetManager::FontManager::getInstance().getFont("doodle_jump");
    scoreText = sf::Text{"", *text_font, static_cast<unsigned int>(50 * (configs::GameConfig::RES_HEIGHT / 700))};
    highScoreText = sf::Text{"", *text_font, static_cast<unsigned int>(50 * (configs::GameConfig::RES_HEIGHT / 700))};
    scoreText.setPosition(configs::GameConfig::RES_WIDTH / 1.95, configs::GameConfig::RES_HEIGHT / 2.6);
    highScoreText.setPosition(configs::GameConfig::RES_WIDTH / 1.5, configs::GameConfig::RES_HEIGHT / 2.05);
    scoreText.setFillColor(sf::Color{25, 30, 65});
    highScoreText.setFillColor(sf::Color{25, 30, 65});

    // Initialize the game over sprite
    //--------------------------------
    gameOverSprite = sf::Sprite{*assetManager::TextureManager::getInstance().getTexture("game_over")};
    gameOverSprite.setScale(
        static_cast<float>(configs::GameConfig::RES_WIDTH / gameOverSprite.getTexture()->getSize().x),
        static_cast<float>(configs::GameConfig::RES_HEIGHT / gameOverSprite.getTexture()->getSize().y));

    // Initialize the game menu sprite
    //--------------------------------
    gameMenuSprite = sf::Sprite{*assetManager::TextureManager::getInstance().getTexture("game_menu")};
    gameMenuSprite.setScale(
        static_cast<float>(configs::GameConfig::RES_WIDTH / gameMenuSprite.getTexture()->getSize().x),
        static_cast<float>(configs::GameConfig::RES_HEIGHT / gameMenuSprite.getTexture()->getSize().y));
}

void gameView::Game::displayStartMenu() { // NOLINT
    window->clear();
    window->draw(gameMenuSprite);
    window->display();
}

void gameView::Game::displayGameOverMenu() {
    scoreText.setString(std::to_string(score->getScore()));
    highScoreText.setString(std::to_string(score->getHighScore()));
    window->clear();
    window->draw(gameOverSprite);
    window->draw(scoreText);
    window->draw(highScoreText);
    window->display();
}

void gameView::Game::run() {

    auto keyPressEvent = std::make_shared<events::KeyPressHandler>();
    auto spaceKeyEvent = std::make_shared<events::SpaceKeyEvent>();
    auto windowCloseEvent = std::make_shared<events::WindowCloseEvent>();

    eventHandler->addEvent(keyPressEvent);
    eventHandler->addEvent(spaceKeyEvent);
    eventHandler->addEvent(windowCloseEvent);

    gameModel::Stopwatch::getInstance().start();

    while (this->isRunning) {
        // Handle and update events
        eventHandler->handleEvents(*window);
        eventHandler->updateEvents();

        // If window closed
        if (windowCloseEvent->isWindowClosed()) {
            isRunning = false;
            break;
        }

        auto duration = gameModel::Stopwatch::getInstance().getDuration();
        const double deltaTime = duration.count();
        gameModel::Stopwatch::getInstance().start();

        // Main game state machine
        switch (currentState) {
        //--------------------------------
        // Game is in start menu
        case StartMenu:
            displayStartMenu();
            if (spaceKeyEvent->isSpacePressed()) {
                currentState = Playing; // Start game
                reset();
            }
            break;

        //--------------------------------
        // Game is playing
        case Playing:
            if (world->isGameOver()) {
                currentState = GameOverMenu; // Game over
            } else {
                // Check if a movement key is pressed
                if (keyPressEvent->isKeyPressed()) {
                    world->handleInput(keyPressEvent->isLeft() ? Left : Right, deltaTime);
                }
                updateGame(deltaTime);
            }
            break;

        //--------------------------------
        // Game is in game over menu
        case GameOverMenu:
            displayGameOverMenu();

            // Restart de game if space is pressed
            if (spaceKeyEvent->isSpacePressed()) {
                currentState = Playing; // Restart game
                reset();
            }
            break;

        //--------------------------------
        // Default case (do nothing)
        default:
            break;
        }
    }
}
