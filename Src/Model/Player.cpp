//
// Created by emir on 11/9/24.
//

#include "Player.h"
#include "../Control/World.h"

gameModel::Player::Player(const double x_location, const double y_location) : Entity(x_location, y_location) {
    width = configs::GameConfig::PLAYER_WIDTH;
    height = configs::GameConfig::PLAYER_HEIGHT;
    x_velocity = configs::GameConfig::PLAYER_SIDE_SPEED;
}

void gameModel::Player::changeState(std::unique_ptr<PlayerState>&& new_state) { specialState = std::move(new_state); }

void gameModel::Player::update(const double delta_time) {
    // If special state is active, update it
    //--------------------------------------
    if (specialState)
        specialState->apply(*this, delta_time);
    else
        // Otherwise, apply the normal physics
        //------------------------------------
        y_velocity -= configs::GameConfig::GRAVITY * delta_time;

    y_location += y_velocity * delta_time;
}

void gameModel::Player::jump() { y_velocity = configs::GameConfig::PLAYER_JUMP_SPEED; }

void gameModel::Player::move(const bool left, const double delta_time) {
    const double direction = left ? -1.0 : 1.0; // Direction (-1 for left, 1 for right)
    this->left = left;

    if ((left && x_velocity > 0) || (!left && x_velocity < 0)) {
        x_velocity = 0;
    }

    x_velocity += direction * configs::GameConfig::PLAYER_ACCELERATION * delta_time;

    if (x_velocity > configs::GameConfig::PLAYER_SIDE_SPEED) {
        x_velocity = configs::GameConfig::PLAYER_SIDE_SPEED;
    } else if (x_velocity < -configs::GameConfig::PLAYER_SIDE_SPEED) {
        x_velocity = -configs::GameConfig::PLAYER_SIDE_SPEED;
    }

    x_location += x_velocity * delta_time;
}

bool gameModel::Player::canJump() const { return y_velocity <= 0; }

void gameModel::Player::checkOutOfWidth() {
    if (x_Max() < 0) {
        x_location = configs::GameConfig::VIEW_WIDTH - width * 3 / 4;
    } else if (x_location > configs::GameConfig::VIEW_WIDTH)
        x_location = -width * 3 / 4;
}

void gameModel::Player::setDirection(const bool left) { this->left = left; }

bool gameModel::Player::getDirection() const { return this->left; }

double gameModel::Player::getCurrentSpeed() const { return this->y_velocity; }

void gameModel::Player::setVelocity(const double new_velocity, const bool vertical) {
    if (vertical)
        this->y_velocity = new_velocity;
    else
        this->x_velocity = new_velocity;
}
