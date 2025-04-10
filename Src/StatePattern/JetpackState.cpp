//
// Created by emir on 1/1/25.
//

#include "JetpackState.h"
#include "../Configs/GameConfig.h"
#include "../Model/Player.h"

gameModel::JetpackState::JetpackState() { remaining_time = 3.0; }

void gameModel::JetpackState::apply(Player& player, const double delta_time) {
    // Player keeps a steady velocity
    // During a time period ???
    player.setVelocity(configs::GameConfig::PLAYER_JUMP_SPEED);
    remaining_time -= delta_time;
    if (remaining_time <= 0) {
        player.changeState(nullptr);
    }
}
