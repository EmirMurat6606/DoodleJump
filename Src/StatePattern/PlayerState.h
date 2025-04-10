/*************************************************************************
 * @file PlayerState.h
 * @brief Interface class for the different states of the player
 * @namespace gameModel
 *************************************************************************/

#ifndef DOODLE_GAME_PLAYERSTATE_H
#define DOODLE_GAME_PLAYERSTATE_H

namespace gameModel {
class Player;
class PlayerState {

protected:
    /**
     * Remaining time of the state
     * \n Used for states that are used during a longer time
     */
    double remaining_time = 0.0;

public:
    /**
     * Default constructor of the PlayerState class
     */
    PlayerState() = default;

    /**
     * Default destructor of the PlayerState class
     */
    virtual ~PlayerState() = default;

    /**
     * Function that updates the state of the player
     * @param player pointer to the player
     * @param delta_time time between two updates (in seconds)
     */
    virtual void apply(Player& player, double delta_time) = 0;
};

} // namespace gameModel
#endif // DOODLE_GAME_PLAYERSTATE_H
