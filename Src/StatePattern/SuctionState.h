/******************************************************************************************
 * @file SuctionState.h
 * @brief Header file for SuctionState class which brings the player in a suction state
 * @namespace gameModel
 ******************************************************************************************/

#ifndef SUCTIONSTATE_H
#define SUCTIONSTATE_H

#include "PlayerState.h"

namespace gameModel {
class SuctionState : public PlayerState {
public:
    /**
     * Constructor of the SuctionState class
     */
    SuctionState();

    /**
     * Function that updates the state of the player
     * @param player pointer to the player
     * @param delta_time time between two updates (in seconds)
     */
    void apply(Player& player, double delta_time) override;
};
} // namespace gameModel

#endif // SUCTIONSTATE_H
