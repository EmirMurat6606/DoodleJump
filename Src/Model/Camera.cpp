//
// Created by emir on 11/9/24.
//

#include "Camera.h"
#include "../Model/Entity.h"

bool gameModel::Camera::newHight(const double player_height) {
    if (player_height > configs::GameConfig::VIEW_HEIGHT / 2) {
        delta = player_height - configs::GameConfig::VIEW_HEIGHT / 2;
        camera_height += delta;
        return true;
    }
    return false;
}

double gameModel::Camera::getDelta() const { return delta; }

double gameModel::Camera::getHeight() const { return camera_height; }

bool gameModel::Camera::outOfBounds(const double entity_y) const { // NOLINT
    return entity_y < 0;
}

std::pair<float, float> gameModel::Camera::scaleToScreen(const double logic_x, const double logic_y) {
    const auto px = static_cast<float>(logic_x * scaleX);
    const auto py = static_cast<float>(configs::GameConfig::VIEW_HEIGHT - logic_y) * scaleY;
    return std::make_pair(px, py);
}
