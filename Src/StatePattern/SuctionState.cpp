//
// Created by emir on 1/1/25.
//

#include "SuctionState.h"
#include "../Configs/GameConfig.h"
#include "../Model/Player.h"

gameModel::SuctionState::SuctionState() { remaining_time = configs::GameConfig::SUCTION_DURATION; }

void gameModel::SuctionState::apply(Player& player, const double delta_time) {
    // Apply the effect of the black hole on player
    // The black hole slows down the player in the direction it is moving
    // It doesn't matter where the black hole is situated on the screen
    if (player.getDirection()) {
        player.updateX(configs::GameConfig::PLAYER_SIDE_SPEED / 3 * delta_time);
    } else {
        player.updateX(-configs::GameConfig::PLAYER_SIDE_SPEED / 3 * delta_time);
    }
    player.setVelocity(player.getCurrentSpeed() - configs::GameConfig::GRAVITY * delta_time);
    remaining_time -= delta_time;
    if (remaining_time <= 0) {
        player.changeState(nullptr);
    }
}
