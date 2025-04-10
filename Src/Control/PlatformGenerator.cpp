//
// Created by emir on 12/1/24.
//

#include "PlatformGenerator.h"
#include "../Model/AEntityFactory.h"
#include "../Model/Camera.h"
#include "../Model/Player.h"
#include "../Model/Random.h"

gameControl::PlatformGenerator::PlatformGenerator(const std::shared_ptr<gameModel::AEntityFactory>& factory)
    : entityFactory(factory) {}

void gameControl::PlatformGenerator::generate(std::vector<std::shared_ptr<gameModel::Platform>>& platforms,
                                              const int height) const {
    // Calculating the highest y-value
    double highestY = platforms.empty() ? 0 : platforms.back()->y_Min();

    // Offset for the highest platform
    // This ensures there are no random pop-ups of platforms in the view
    constexpr double offset = 20;

    // If the highest platform is already above the viewHeight (+ offset), no need to generate new platforms
    if (highestY >= configs::GameConfig::VIEW_HEIGHT + offset) {
        return;
    }

    // Create the weights for the platform types
    //------------------------------------------
    std::vector<int> weights;
    if (height < configs::GameConfig::STAGE_ONE)
        weights = {100, 0, 0, 0}; // Only static platforms
    else if (height < configs::GameConfig::STAGE_TWO)
        weights = {80, 20, 0, 0}; // Static and horizontal platforms
    else if (height < configs::GameConfig::STAGE_THREE) {
        weights = {70, 30, 0, 0}; // Static and horizontal platforms
    } else if (height < configs::GameConfig::STAGE_FOUR) {
        weights = {55, 30, 15, 0}; // Static, horizontal and vertical platforms
    } else {                       // Every type of platform
        int static_weight = std::max(30, 40 - (height - configs::GameConfig::STAGE_FOUR) / 200);
        int horizontal_weight = std::max(10, 15 - (height - configs::GameConfig::STAGE_FOUR) / 250);
        int vertical_weight = std::max(12, 18 - (height - configs::GameConfig::STAGE_FOUR) / 180);
        int temporary_weight = std::min(50, 20 + (height - configs::GameConfig::STAGE_FOUR) / 100);
        weights = {static_weight, horizontal_weight, vertical_weight, temporary_weight};
    }

    bool generating = true;

    while (generating) {
        constexpr double jump_height_offset = 2.0; // Offset for the jump height

        // Generate random x coordinate within range
        const double x_coordinate = gameModel::Random::getInstance().randomValue(
            0.0, configs::GameConfig::VIEW_WIDTH - configs::GameConfig::PLATFORM_WIDTH);

        // Generate the y_coordinate
        const double y_height =
            std::min(static_cast<double>(configs::GameConfig::PLAYER_JUMP_HEIGHT) - jump_height_offset,
                     configs::GameConfig::GROWTH_FACTOR * (height <= 400 ? 400 : height));
        const double y_coordinate = highestY + configs::GameConfig::minVerticalSpacing + y_height;

        // Add the platform
        platforms.push_back(
            createPlatform(x_coordinate, y_coordinate, gameModel::Random::getInstance().randomIndex(weights)));

        // Update highest y value
        highestY = y_coordinate;

        if (highestY >= configs::GameConfig::VIEW_HEIGHT + offset) {
            generating = false;
        }
    }
}

std::shared_ptr<gameModel::Platform> gameControl::PlatformGenerator::createPlatform(const double x, const double y,
                                                                                    const int index) const {
    switch (index) {
    case 0:
        return entityFactory->createPlatform(x, y, SPlatform);
    case 1:
        return entityFactory->createPlatform(x, y, HPlatform);
    case 2:
        return entityFactory->createPlatform(x, y, VPlatform);
    case 3:
        return entityFactory->createPlatform(x, y, TPlatform);
    default:
        return entityFactory->createPlatform(x, y, SPlatform);
    }
}
