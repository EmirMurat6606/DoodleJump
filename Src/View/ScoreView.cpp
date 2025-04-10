//
// Created by emir on 11/23/24.
//

#include "ScoreView.h"
#include "../AssetManager/FontManager.h"
#include "../Exceptions/FontLoadException.h"
#include "../Model/Camera.h"

gameView::ScoreView::ScoreView(const std::weak_ptr<sf::RenderWindow>& game_window) : game_window(game_window) {
    font = *assetManager::FontManager::getInstance().getFont("doodle_jump");
    scoreText.setFont(font);
    scoreText.setFillColor(color);
    scoreText.setCharacterSize(static_cast<int>(50 * configs::GameConfig::RES_HEIGHT / 700));
    scoreText.setPosition(position.first, position.second);
}

void gameView::ScoreView::draw() const { game_window.lock()->draw(scoreText); }

void gameView::ScoreView::update(const gameModel::Score& score) {
    scoreText.setString(std::to_string(score.getScore()));
    draw();
}
