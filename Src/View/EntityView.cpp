//
// Created by emir on 11/10/24.
//

#include "EntityView.h"
#include "../Model/Camera.h"
#include "../Model/Entity.h"

void gameView::EntityView::draw() const { game_window.lock()->draw(entity_sprite); }

gameView::EntityView::EntityView(const std::weak_ptr<sf::RenderWindow>& game_window) : game_window(game_window) {}

void gameView::EntityView::update(const gameModel::Entity& entity) {
    const auto [px, py] = gameModel::Camera::scaleToScreen(entity.x_Min(), entity.y_Max());
    entity_sprite.setPosition(px, py);
    draw();
}
