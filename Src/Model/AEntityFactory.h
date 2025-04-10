/*****************************************************************************************
 * @file AEntityFactory.h
 * @brief This file contains the declaration of the EntityFactory class
 * The EntityFactory class is responsible for creating entities in the game
 * This class follows an abstract factory pattern
 * @namespace gameModel
 * @details Abstract factory design pattern which provides an interface
 * for creating abstract objects without specifying their concrete classes
 *****************************************************************************************/

#ifndef DOODLE_GAME_ENTITYFACTORY_H
#define DOODLE_GAME_ENTITYFACTORY_H

#include <memory>

#include "Bonus.h"
#include "Obstacle.h"
#include "Platform.h"

namespace gameModel {
class BGTile;
class Score;
class Player;
} // namespace gameModel

namespace gameModel {

class AEntityFactory {

public:
    /**
     * Default constructor of the EntityFactory class
     */
    AEntityFactory() = default;

    /**
     * Default virtual destructor of the EntityFactory class
     */
    virtual ~AEntityFactory() = default;

    /**
     * Pure virtual function
     * \n Create a player
     * @param X_location initial x location of the player
     * @param Y_location initial y location of the player
     * @return a pointer to the player
     */
    virtual std::shared_ptr<Player> createPlayer(double X_location, double Y_location) = 0;

    /**
     * Pure virtual function
     * \n Create a platform
     * @param platform the type of the platform
     * @param X_location initial x location of the platform
     * @param Y_location initial y location of the platform
     * @return a pointer to the platform
     */
    virtual std::shared_ptr<Platform> createPlatform(double X_location, double Y_location, PlatformType platform) = 0;

    /**
     * Pure virtual function
     * \n Create a bonus
     * @param bonus the type of the bonus
     * @param X_location initial x location of the bonus
     * @param Y_location initial y location of the bonus
     * @return a pointer to the bonus
     */
    virtual std::shared_ptr<Bonus> createBonus(double X_location, double Y_location, BonusType bonus) = 0;

    /**
     * Pure virtual function
     * \n Create a background tile
     * @param X_location initial x location of the bg tile
     * @param Y_location initial y location of the bg tile
     * @return a pointer to the background tile
     */
    virtual std::shared_ptr<BGTile> createBGTile(double X_location, double Y_location) = 0;

    /**
     * Pure virtual function
     * \n Create an obstacle
     * @param X_location initial x location of the obstacle
     * @param Y_location initial y location of the obstacle
     * @param obstacle the type of the obstacle
     * @return a pointer to the obstacle
     */
    virtual std::shared_ptr<Obstacle> createObstacle(double X_location, double Y_location, ObstacleType obstacle) = 0;

    /**
     * Pure virtual function
     * \n Create a score object
     * @return a pointer to the score object
     */
    virtual std::shared_ptr<Score> createScore() = 0;
};

} // namespace gameModel

#endif // DOODLE_GAME_ENTITYFACTORY_H
