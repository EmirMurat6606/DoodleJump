//
// Created by emir on 1/1/25.
//

#include "SpringState.h"
#include "../Configs/GameConfig.h"
#include "../Model/Player.h"
#include <cmath>

void gameModel::SpringState::apply(Player& player, double delta_time) {
    // Height = velocity^2 / 2 * g
    // 5 x Height: (sqrt(5) * velocity)^2 / 2 * g
    player.setVelocity(configs::GameConfig::PLAYER_JUMP_SPEED * sqrt(5.0), true);
    // This bonus is used only once
    player.changeState(nullptr);
}
