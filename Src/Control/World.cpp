//
// Created by emir on 11/9/24.
//

#include "World.h"

#include <algorithm>

#include "../Model/AEntityFactory.h"
#include "../Model/BGTile.h"
#include "../Model/Entity.h"
#include "../Model/Platform.h"
#include "../Model/Player.h"
#include "../Model/Score.h"

gameControl::World::World(const std::shared_ptr<gameModel::AEntityFactory>& factory,
                          const std::shared_ptr<gameModel::Score>& score)
    : entityFactory(factory), game_score(score) {
    doodler = entityFactory->createPlayer(50, 0);                                  // Begin position player
    bgTileGenerator->generate(bg_tiles);                                           // Begin background tiles
    platformGenerator->generate(platforms, static_cast<int>(camera->getHeight())); // Begin platforms
}

void gameControl::World::update(const double deltaTime) {

    // Check if player is out of bounds and end the game
    //----------------------------------------------
    if (camera->outOfBounds(doodler->y_Min())) {
        game_over = true;
        return;
    }

    // Handle wrapping of player across horizontal bounds
    doodler->checkOutOfWidth();

    // Update platforms and check for collisions
    //----------------------------------------------
    updatePlatforms(deltaTime);

    // Update obstacles
    //----------------------------------------------
    updateObstacles(deltaTime);

    // Update player's position
    //----------------------------------------------
    doodler->update(deltaTime);

    // Update view if player has reached a new height
    //----------------------------------------------
    updateView(deltaTime);

    // Notify all observers of the updated subjects
    //----------------------------------------------
    for (const auto& tile : bg_tiles)
        tile->notify(*tile);
    for (const auto& obstacle : obstacles)
        obstacle->notify(*obstacle);
    for (const auto& platform : platforms)
        platform->notify(*platform);
    for (const auto& game_bonus : bonuses)
        game_bonus->notify(*game_bonus);
    doodler->notify(*doodler);
    game_score->notify(*game_score);
}

bool gameControl::World::isGameOver() const { return game_over; }

bool gameControl::World::collisionDetect(const std::shared_ptr<gameModel::Entity>& entity) const {
    constexpr double margin_x = 1.0;
    constexpr double margin_y = 0.2;
    const bool collision = doodler->x_Max() > entity->x_Min() + margin_x &&
                           doodler->x_Min() < entity->x_Max() - margin_x &&
                           doodler->y_Min() < entity->y_Max() + margin_y &&
                           doodler->y_Max() > entity->y_Max() + configs::GameConfig::PLAYER_HEIGHT * 1 / 2;
    return collision;
}

void gameControl::World::updatePlatforms(const double delta_time) {
    bool can_jump = doodler->canJump();
    for (auto it = platforms.begin(); it != platforms.end();) {
        auto& platform = *it;
        const PlatformType platformType = platform->getType(); // Cache platform type

        // Handle collisions if not already detected
        if (can_jump && collisionDetect(platform)) {
            if (platform->isJumped())
                game_score->update(platformType); // Update score
            else
                platform->jump();

            // If there is a bonus, check for collision
            if (platform->getBonus() && collisionDetect(platform->getBonus())) {
                platform->getBonus()->apply(*doodler); // Apply bonus
            } else
                doodler->jump(); // Or normal jump

            can_jump = false; // Prevent further jumps this cycle

            // Remove platform if it's temporary
            if (platformType == TPlatform) {
                if (platform->getBonus()) {
                    auto bonus = platform->getBonus();
                    auto bonusIt = std::find(bonuses.begin(), bonuses.end(), bonus);
                    if (bonusIt != bonuses.end()) {
                        bonuses.erase(bonusIt); // Remove the bonus from the vector
                    }
                }
                it = platforms.erase(it);
                continue;
            }
        }

        // If vertical platform is out of bounds, remove it
        // Vertical platforms need an additional check
        if (platform->getType() == VPlatform) {
            if (camera->outOfBounds(platform->y_Max())) {
                it = platforms.erase(it);
                continue;
            }
        }

        // Update the platform
        platform->update(delta_time);
        ++it;
    }
}

void gameControl::World::updateObstacles(const double delta_time) {
    for (const auto& obstacle : obstacles) {
        obstacle->update(delta_time);
        if (obstacle->y_Max() < configs::GameConfig::VIEW_HEIGHT)
            obstacle->activate();
        if (obstacle->isActive() && obstacle->getType() == BlackHole) {
            obstacle->apply(*doodler);
            obstacle->deActivate();
        }
    }
}

void gameControl::World::updateView(const double delta_time) {
    if (!camera->newHight(doodler->y_Max()))
        return;

    auto update = [&](auto& entity_list) {
        for (auto it = entity_list.begin(); it != entity_list.end();) {
            auto& entity = *it;
            entity->updateY(-camera->getDelta());
            if (camera->outOfBounds(entity->y_Max())) {
                it = entity_list.erase(it);
            } else {
                ++it;
            }
        }
    };
    update(platforms);
    update(bg_tiles);
    update(bonuses);
    update(obstacles);
    doodler->updateY(-camera->getDelta());
    // Generate new background tiles
    bgTileGenerator->generate(bg_tiles);
    // Generate new platforms
    platformGenerator->generate(platforms, static_cast<int>(camera->getHeight()));
    // Generate new bonuses
    bonusGenerator->generate(bonuses, platforms.back());
    // Generate new obstacles
    obstacleGenerator->generate(obstacles, static_cast<int>(camera->getHeight()), delta_time);
    // Update game score
    game_score->update(*camera);
}

void gameControl::World::handleInput(const KeyPress& key, const double delta_time) const {
    switch (key) {
    case Left:
        doodler->move(true, delta_time);
        break;
    case Right:
        doodler->move(false, delta_time);
        break;
    default:
        break;
    }
}
