/*****************************************************************************************
 * @file CEntityFactory.h
 * @brief 'EntityFactory' class is a concrete class that inherits from 'gameModel::AEntityFactory'.
 * /n It is responsible for creating the concrete entities in the game.
 * @namespace gameView
 *****************************************************************************************/

#ifndef ENTITYFACTORY_SFML_H
#define ENTITYFACTORY_SFML_H

#include "../Model/AEntityFactory.h"

#include <SFML/Graphics.hpp>
#include <memory>

namespace gameView {
class CEntityFactory : public gameModel::AEntityFactory {

    /**
     * Weak pointer to the game_window
     * Used to create entities referring to the game window
     */
    std::weak_ptr<sf::RenderWindow> game_window;

public:
    /**
     * Constructor of the EntityFactory
     * @param game_window weak pointer to the game window
     */
    explicit CEntityFactory(std::weak_ptr<sf::RenderWindow> game_window);

    /**
     * Destructor of the EntityFactory
     */
    ~CEntityFactory() override = default;

    /**
     * Create a player
     * @param X_location initial x location of the player
     * @param Y_location initial y location of the player
     * @return a pointer to the player
     */
    std::shared_ptr<gameModel::Player> createPlayer(double X_location, double Y_location) override;

    /**
     * Create a platform
     * @param X_location initial x location of the platform
     * @param Y_location initial y location of the platform
     * @param platform type of the platform (static, horizontal, vertical, temporary)
     * @return a pointer to the platform
     */
    std::shared_ptr<gameModel::Platform> createPlatform(double X_location, double Y_location,
                                                        PlatformType platform) override;

    /**
     * Create a bonus
     * @param X_location initial x location of the bonus
     * @param Y_location initial y location of the bonus
     * @param bonus type of the bonus (spring, jetpack)
     * @return a pointer to the bonus
     */
    std::shared_ptr<gameModel::Bonus> createBonus(double X_location, double Y_location, BonusType bonus) override;

    /**
     * Create a background tile
     * @param X_location initial x location of the background tile
     * @param Y_location initial y location of the background tile
     * @return a pointer to the background tile
     */
    std::shared_ptr<gameModel::BGTile> createBGTile(double X_location, double Y_location) override;

    /**
     * Create an obstacle
     * @param X_location initial x location of the obstacle
     * @param Y_location initial y location of the obstacle
     * @param obstacle type of the obstacle (black hole)
     * @return a pointer to the obstacle
     */
    std::shared_ptr<gameModel::Obstacle> createObstacle(double X_location, double Y_location,
                                                        ObstacleType obstacle) override;

    /**
     * Create a score
     * @return a pointer to the score
     */
    std::shared_ptr<gameModel::Score> createScore() override;
};
} // namespace gameView

#endif // ENTITYFACTORY_SFML_H
