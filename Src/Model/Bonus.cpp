//
// Created by emir on 11/9/24.
//

#include "Bonus.h"
#include "../StatePattern/JetpackState.h"
#include "../StatePattern/SpringState.h"
#include "Player.h"
#include <cmath>

#include "../Configs/GameConfig.h"

gameModel::Bonus::Bonus(const double x_location, const double y_location) : Entity(x_location, y_location) {}

void gameModel::Bonus::apply(Player& player) const { /* DO NOTHING */ }

gameModel::SpringBonus::SpringBonus(const double x_location, const double y_location) : Bonus(x_location, y_location) {
    width = configs::GameConfig::SPRING_WIDTH;
    height = configs::GameConfig::SPRING_HEIGHT;
}

BonusType gameModel::SpringBonus::getType() const { return BonusType::Spring; }

void gameModel::SpringBonus::apply(Player& player) const { player.changeState(std::make_unique<SpringState>()); }

gameModel::JetpackBonus::JetpackBonus(const double x_location, const double y_location)
    : Bonus(x_location, y_location) {
    width = configs::GameConfig::JETPACK_WIDTH;
    height = configs::GameConfig::JETPACK_HEIGHT;
}

BonusType gameModel::JetpackBonus::getType() const { return BonusType::Jetpack; }

void gameModel::JetpackBonus::apply(Player& player) const { player.changeState(std::make_unique<JetpackState>()); }
