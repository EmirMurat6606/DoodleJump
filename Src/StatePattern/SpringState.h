/*****************************************************************************************
 * @file SpringState.h
 * @brief Definition of the SpringState class that applies a spring jump to the player entity
 * @namespace gameModel
 *****************************************************************************************/

#ifndef SPRINGSTATE_H
#define SPRINGSTATE_H

#include "PlayerState.h"

namespace gameModel {

class SpringState : public PlayerState {

    /**
     * Function that updates the state of the player
     * @param player pointer to the player
     * @param delta_time time between two updates (in seconds)
     */
    void apply(Player& player, double delta_time) override;
};
} // namespace gameModel

#endif // SPRINGSTATE_H
