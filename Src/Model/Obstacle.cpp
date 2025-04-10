//
// Created by emir on 12/13/24.
//

#include "Obstacle.h"
#include "../StatePattern/SuctionState.h"
#include "Player.h"

gameModel::Obstacle::Obstacle(const double x_location, const double y_location) : Entity(x_location, y_location) {}

bool gameModel::Obstacle::isActive() const { return this->active; }

void gameModel::Obstacle::activate() { this->active = true; }

void gameModel::Obstacle::deActivate() { this->active = false; }

void gameModel::Obstacle::apply(Player& player) const { /* DO NOTHING */ }

gameModel::BlackHoleObstacle::BlackHoleObstacle(const double x_location, const double y_location)
    : Obstacle(x_location, y_location) {}

ObstacleType gameModel::BlackHoleObstacle::getType() const { return ObstacleType::BlackHole; }

void gameModel::BlackHoleObstacle::activate() {
    if (!activated) {
        Obstacle::activate();
        activated = true;
    }
}

void gameModel::BlackHoleObstacle::apply(Player& player) const { player.changeState(std::make_unique<SuctionState>()); }
