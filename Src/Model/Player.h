/*****************************************************************************
 * @file Player.h
 * @brief The Player class represents the player in the game.
 * @namespace gameModel
 *****************************************************************************/

#ifndef DOODLE_GAME_PLAYER_H
#define DOODLE_GAME_PLAYER_H

#include "../StatePattern/PlayerState.h"
#include "Entity.h"

namespace gameModel {

class Player : public Entity {

    /**
     * The special state of the player
     * \n Used for applying temporary states passed by other entities
     * \n Temporary states can be passed by bonuses, obstacles etc.
     */
    std::unique_ptr<PlayerState> specialState;

    /**
     * The current velocity of the player in the y direction
     * \n Initialized on a high value for a fast start
     */
    double y_velocity = 200;

    /**
     * The current velocity of the player in the x direction
     * \n Initialized on zero
     */
    double x_velocity = 0;

    /**
     * Indicates if the player is facing left/right
     * \n true = left
     * \n false = right
     */
    bool left = true;

public:
    /**
     * Constructor of the Player class
     * @param x_location initial x location of the player
     * @param y_location initial y location of the player
     */
    Player(double x_location, double y_location);

    /**
     * Destructor of the Player class
     */
    ~Player() override = default;

    /**
     * Changes the special state of the player
     * @param new_state sets the player in a new state
     * @attention Special states are represented by entities and have an effect on player
     */
    void changeState(std::unique_ptr<PlayerState>&& new_state);

    /**
     * Update the player position
     * @param delta_time time between two updates
     */
    void update(double delta_time) override;

    /**
     * Jump the player up
     */
    void jump();

    /**
     * Changes the position of the doodler either to left or right
     * @param left true if left, false if right
     * @param delta_time time between two updates
     */
    void move(bool left, double delta_time);

    /**
     * Determines if the player can jump on a platform
     * \n A player can only jump when its velocity is zero or negative
     */
    [[nodiscard]] bool canJump() const;

    /**
     * Checks if the player is out of bounds on the left or ride side
     */
    void checkOutOfWidth();

    /**
     * Set the horizontal direction of the player
     * \n Direction is either left or right
     */
    void setDirection(bool left);

    /**
     * Gets the direction of the player
     * @return If true (LEFT), false (RIGHT)
     */
    [[nodiscard]] bool getDirection() const;

    /**
     * Get the current speed of the player
     * @return the speed as a double
     */
    [[nodiscard]] double getCurrentSpeed() const;

    /**
     * Set the velocity of the player
     * @param new_velocity the new  velocity of the player
     * @param vertical determines if new_velocity changes the vertical or horizontal velocity
     */
    void setVelocity(double new_velocity, bool vertical = true);
};
} // namespace gameModel

#endif // DOODLE_GAME_PLAYER_H
