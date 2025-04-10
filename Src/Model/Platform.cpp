//
// Created by emir on 11/9/24.
//

#include "Platform.h"
#include "Bonus.h"
#include "Camera.h"

gameModel::Platform::Platform(const double x_location, const double y_location) : Entity(x_location, y_location) {
    width = configs::GameConfig::PLATFORM_WIDTH;
    height = configs::GameConfig::PLATFORM_HEIGHT;
}

bool gameModel::Platform::isJumped() const { return jumped; }

void gameModel::Platform::attachBonus(const std::shared_ptr<Bonus>& bonus) { this->bonus = bonus; }

void gameModel::Platform::jump() { this->jumped = true; }

std::shared_ptr<gameModel::Bonus> gameModel::Platform::getBonus() const { return this->bonus; }

gameModel::MovingPlatform::MovingPlatform(const double x_location, const double y_location)
    : Platform(x_location, y_location) {}

bool gameModel::MovingPlatform::getDirection() const { return direction; }

gameModel::StaticPlatform::StaticPlatform(const double x_location, const double y_location)
    : Platform(x_location, y_location) {}

PlatformType gameModel::StaticPlatform::getType() const { return PlatformType::SPlatform; }

void gameModel::HorizontalPlatform::checkDirection() {
    if (direction) {
        if (x_Max() >= configs::GameConfig::VIEW_WIDTH) {
            direction = false;
        }
    } else {
        if (x_Min() <= 0) {
            direction = true;
        }
    }
}

gameModel::HorizontalPlatform::HorizontalPlatform(const double x_location, const double y_location)
    : MovingPlatform(x_location, y_location) {}

PlatformType gameModel::HorizontalPlatform::getType() const { return PlatformType::HPlatform; }

void gameModel::HorizontalPlatform::update(const double delta_time) {
    checkDirection();
    double x_change = 0.0;
    if (direction)
        x_change = horizontalSpeed * delta_time;
    else
        x_change = -horizontalSpeed * delta_time;
    x_location += x_change;
    if (bonus)
        bonus->updateX(x_change);
}

void gameModel::VerticalPlatform::checkDirection() {
    if (direction) {
        if (y_Min() >= original_y_pos + range) {
            direction = false;
        }
    } else {
        if (y_Min() <= original_y_pos) {
            direction = true;
        }
    }
}

gameModel::VerticalPlatform::VerticalPlatform(const double x_location, const double y_location)
    : MovingPlatform(x_location, y_location), original_y_pos(y_location) {}

PlatformType gameModel::VerticalPlatform::getType() const { return PlatformType::VPlatform; }

void gameModel::VerticalPlatform::update(const double delta_time) {
    checkDirection();
    double y_change = 0.0;
    if (direction)
        y_change = verticalSpeed * delta_time;
    else
        y_change = -verticalSpeed * delta_time;
    y_location += y_change;
    if (bonus)
        bonus->updateY(y_change);
}

void gameModel::VerticalPlatform::updateY(const double delta_y) {
    MovingPlatform::updateY(delta_y);
    original_y_pos += delta_y;
}

gameModel::TemporaryPlatform::TemporaryPlatform(const double x_location, const double y_location)
    : Platform(x_location, y_location) {}

PlatformType gameModel::TemporaryPlatform::getType() const { return PlatformType::TPlatform; }
