/*****************************************************************************************
 * @file JetpackState.h
 * @brief Definition of the JetpackState class that applies a jetpack to the player entity
 * @namespace gameModel
 *****************************************************************************************/
#ifndef JETPACKSTATE_H
#define JETPACKSTATE_H

#include "PlayerState.h"

namespace gameModel {
class JetpackState : public PlayerState {
public:
    /**
     * Constructor of the JetpackState class
     */
    JetpackState();

    /**
     * Function that updates the state of the player
     * @param player pointer to the player
     * @param delta_time time between two updates (in seconds)
     */
    void apply(Player& player, double delta_time) override;
};
} // namespace gameModel

#endif // JETPACKSTATE_H
