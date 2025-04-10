/*************************************************************************************************
 * @file Obstacle.h
 * @brief This file contains the declaration of the Obstacle class and its subclasses
 * @see Obstacle.cpp
 *************************************************************************************************/

#ifndef DOODLE_GAME_OBSTACLE_H
#define DOODLE_GAME_OBSTACLE_H

#include "Entity.h"

/**
 * @enum ObstacleType represents the types of obstacles
 * \n BlackHole - Black Hole obstacle
 */
enum ObstacleType { BlackHole };

namespace gameModel {
class Player;
class Obstacle : public Entity {
protected:
    /**
     * Boolean that indicates if the obstacle is active
     * \n so in screen
     */
    bool active = false;

public:
    /**
     * Constructor of the Obstacle class
     */
    Obstacle(double x_location, double y_location);

    /**
     * Destructor of the Obstacle class
     */
    virtual ~Obstacle() = default;

    /**
     * Determines if the black hole is active and in screen
     * @return a boolean true if active, else false
     */
    [[nodiscard]] bool isActive() const;

    /**
     * Activates the obstacle if it is in screen
     */
    virtual void activate();

    /**
     * De-activates the obstacle when necessary
     * \n Depends on type of obstacle
     */
    virtual void deActivate();

    /**
     * Get the type of the entity
     */
    [[nodiscard]] virtual ObstacleType getType() const = 0;

    /**
     * Passes a new state to the player
     * \n Inherited only if the obstacle has a special effect
     */
    virtual void apply(Player& player) const;
};

// BlackHoleObstacle
class BlackHoleObstacle : public Obstacle {

    /**
     * Check mechanism to ensure that black hole was activated
     * \n and doesn't get activated again
     */
    bool activated = false;

public:
    /**
     * Constructor of the BlackHoleObstacle class
     */
    BlackHoleObstacle(double x_location, double y_location);

    /**
     * Destructor of the BlackHoleObstacle class
     */
    ~BlackHoleObstacle() override = default;

    /**
     * Get the type of the entity
     */
    [[nodiscard]] ObstacleType getType() const override;

    /**
     * Activates the black hole
     * \n Overridden from obstacle
     */
    void activate() override;

    /**
     * Applies the Suction State to the player
     * @param player the player to which the state is applied
     */
    void apply(Player& player) const override;
};
} // namespace gameModel

#endif // DOODLE_GAME_OBSTACLE_H
