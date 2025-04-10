//
// Created by emir on 11/10/24.
//

#include "CEntityFactory.h"
#include "../Model/BGTile.h"
#include "../Model/Bonus.h"
#include "../Model/Obstacle.h"
#include "../Model/Platform.h"
#include "../Model/Player.h"
#include "../Model/Score.h"
#include "BGTileView.h"
#include "BonusView.h"
#include "ObstacleView.h"
#include "PlatformView.h"
#include "PlayerView.h"
#include "ScoreView.h"

gameView::CEntityFactory::CEntityFactory(std::weak_ptr<sf::RenderWindow> game_window)
    : game_window(std::move(game_window)) {}

std::shared_ptr<gameModel::Player> gameView::CEntityFactory::createPlayer(double X_location, double Y_location) {
    std::shared_ptr<gameModel::Player> player = std::make_shared<gameModel::Player>(X_location, Y_location);
    std::shared_ptr<PlayerView> player_view = std::make_shared<PlayerView>(game_window);
    player->attach(player_view);
    return player;
}

std::shared_ptr<gameModel::Platform> gameView::CEntityFactory::createPlatform(double X_location, double Y_location,
                                                                              const PlatformType platform) {
    std::shared_ptr<gameModel::Platform> platform_ptr = nullptr;
    std::shared_ptr<PlatformView> platform_view = nullptr;
    if (platform == SPlatform) {
        platform_ptr = std::make_shared<gameModel::StaticPlatform>(X_location, Y_location);
        platform_view = std::make_shared<StaticPlatformView>(game_window);
    }
    if (platform == HPlatform) {
        platform_ptr = std::make_shared<gameModel::HorizontalPlatform>(X_location, Y_location);
        platform_view = std::make_shared<HorizontalPlatformView>(game_window);
    }
    if (platform == VPlatform) {
        platform_ptr = std::make_shared<gameModel::VerticalPlatform>(X_location, Y_location);
        platform_view = std::make_shared<VerticalPlatformView>(game_window);
    }
    if (platform == TPlatform) {
        platform_ptr = std::make_shared<gameModel::TemporaryPlatform>(X_location, Y_location);
        platform_view = std::make_shared<TemporaryPlatformView>(game_window);
    }
    platform_ptr->attach(platform_view);
    return platform_ptr;
}

std::shared_ptr<gameModel::Bonus> gameView::CEntityFactory::createBonus(double X_location, double Y_location,
                                                                        const BonusType bonus) {
    std::shared_ptr<gameModel::Bonus> bonus_ptr = nullptr;
    std::shared_ptr<BonusView> bonus_view = nullptr;
    if (bonus == Jetpack) {
        bonus_ptr = std::make_shared<gameModel::JetpackBonus>(X_location, Y_location);
        bonus_view = std::make_shared<JetpackBonusView>(game_window);
    }
    if (bonus == Spring) {
        bonus_ptr = std::make_shared<gameModel::SpringBonus>(X_location, Y_location);
        bonus_view = std::make_shared<SpringBonusView>(game_window);
    }
    bonus_ptr->attach(bonus_view);
    return bonus_ptr;
}

std::shared_ptr<gameModel::BGTile> gameView::CEntityFactory::createBGTile(double X_location, double Y_location) {
    std::shared_ptr<gameModel::BGTile> bgTile = std::make_shared<gameModel::BGTile>(X_location, Y_location);
    std::shared_ptr<BGTileView> bgTile_view = std::make_shared<BGTileView>(game_window);
    bgTile->attach(bgTile_view);
    return bgTile;
}

std::shared_ptr<gameModel::Obstacle> gameView::CEntityFactory::createObstacle(double X_location, double Y_location,
                                                                              const ObstacleType obstacle) {
    std::shared_ptr<gameModel::Obstacle> obstacle_ptr = nullptr;
    std::shared_ptr<ObstacleView> obstacle_view = nullptr;
    if (obstacle == BlackHole) {
        obstacle_ptr = std::make_shared<gameModel::BlackHoleObstacle>(X_location, Y_location);
        obstacle_view = std::make_shared<BlackHoleObstacleView>(game_window);
    }
    obstacle_ptr->attach(obstacle_view);
    return obstacle_ptr;
}

std::shared_ptr<gameModel::Score> gameView::CEntityFactory::createScore() {
    std::shared_ptr<gameModel::Score> score = std::make_shared<gameModel::Score>();
    std::shared_ptr<ScoreView> score_view = std::make_shared<ScoreView>(game_window);
    score->attach(score_view);
    return score;
}
