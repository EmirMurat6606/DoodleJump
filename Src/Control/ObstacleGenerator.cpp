//
// Created by emir on 12/13/24.
//

#include "ObstacleGenerator.h"
#include "../Configs/GameConfig.h"
#include "../Model/AEntityFactory.h"
#include "../Model/Random.h"

gameControl::ObstacleGenerator::ObstacleGenerator(const std::shared_ptr<gameModel::AEntityFactory>& factory)
    : entityFactory(factory) {}

void gameControl::ObstacleGenerator::generate(std::vector<std::shared_ptr<gameModel::Obstacle>>& obstacles,
                                              const int height, const double delta_time) const {

    static double timeAccumulator = 0.0; // Accumulate time between frames

    // Only generate if unlocked
    if (height < configs::GameConfig::BLACK_HOLE_UNLOCK)
        return;

    // Accumulate the time
    timeAccumulator += delta_time;

    // Check the timer
    if (timeAccumulator >= configs::GameConfig::BLACK_HOLE_INTERVAL) {
        timeAccumulator = 0.0; // Reset de timer

        // Generate random x-coordinate in range
        constexpr double offset = 50;
        const double x_coordinate = gameModel::Random::getInstance().randomValue(
            0.0, configs::GameConfig::VIEW_WIDTH - configs::GameConfig::BLACK_HOLE_WIDTH);
        constexpr double y_coordinate = configs::GameConfig::VIEW_HEIGHT + offset;

        // Create new obstacle
        const auto obstacle = createObstacle(x_coordinate, y_coordinate, 0);
        obstacles.push_back(obstacle);
    }
}

std::shared_ptr<gameModel::Obstacle> gameControl::ObstacleGenerator::createObstacle(const double x, const double y,
                                                                                    const int index) const {
    switch (index) {
    case 0:
        return entityFactory->createObstacle(x, y, BlackHole);
    default:
        return entityFactory->createObstacle(x, y, BlackHole);
    }
}
