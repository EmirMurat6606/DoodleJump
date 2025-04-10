/*****************************************************************************************
 * @file GameConfig.h
 * @brief This file contains the configurations for the doodle jump game
 * @ingroup configs
 *****************************************************************************************/

#ifndef GAMECONFIG_H
#define GAMECONFIG_H

namespace configs {
class GameConfig {
public:
    // Framerate configurations
    //-------------------------------------------------------------------------------------
    static constexpr int FPS = 60;

    // Resolution configurations
    //-------------------------------------------------------------------------------------
    static constexpr double RES_HEIGHT = 700;
    static constexpr double RES_WIDTH = RES_HEIGHT / 1.75; // DO NOT CHANGE THIS VALUE

    // Normalized coordinates
    //-------------------------------------------------------------------------------------
    static constexpr double VIEW_WIDTH = 100;
    static constexpr double VIEW_HEIGHT = 175;

    // World configurations
    //-------------------------------------------------------------------------------------
    static constexpr double GRAVITY = 245.0;

    // Player configurations
    //-------------------------------------------------------------------------------------
    static constexpr double PLAYER_WIDTH = 15;
    static constexpr double PLAYER_HEIGHT = 15.0;
    static constexpr double PLAYER_JUMP_SPEED = 175.0;
    static constexpr double PLAYER_SIDE_SPEED = 80.0;
    static constexpr double PLAYER_ACCELERATION = 200.0;
    static constexpr double PLAYER_JUMP_HEIGHT = 60.0;

    // Platform configurations
    //-------------------------------------------------------------------------------------
    static constexpr double PLATFORM_WIDTH = 18.0;
    static constexpr double PLATFORM_HEIGHT = 3.0;

    // Bonus configurations
    //-------------------------------------------------------------------------------------
    static constexpr double SPRING_WIDTH = 4.0;
    static constexpr double SPRING_HEIGHT = 4.0;
    static constexpr double JETPACK_WIDTH = 4.0;
    static constexpr double JETPACK_HEIGHT = 6.0;
    static constexpr double JETPACK_DURATION = 3.0;
    // Probabilities in percentage
    // Make sure the sum of all probabilities is 100
    static constexpr int JETPACK_PROB = 30;
    static constexpr int SPRING_PROB = 70;
    // Probability for a bonus to appear on a platform
    static constexpr int BONUS_PROB = 5;

    // Obstacle configurations
    //-------------------------------------------------------------------------------------
    static constexpr double BLACK_HOLE_WIDTH = 10.0;
    static constexpr double BLACK_HOLE_HEIGHT = 10.0;
    static constexpr int BLACK_HOLE_UNLOCK = 4000; // Score at which black holes start appearing
    static constexpr double SUCTION_DURATION = 2.0;
    static constexpr double BLACK_HOLE_INTERVAL = 10.0; // In seconds, time for new black hole to appear

    // Background configurations
    //-------------------------------------------------------------------------------------
    static constexpr int TILE_COUNT_X = 1;
    static constexpr int TILE_COUNT_Y = 1;

    // Platform difficulty configurations (in terms of camera/player height)
    // To change the frequency, change weights in gameControl::PlatformGenerator::generate
    //-------------------------------------------------------------------------------------

    static constexpr double minVerticalSpacing = 4.0; // Minimum vertical spacing between platforms
    static constexpr double GROWTH_FACTOR = 0.006;    // Factor for the linear growth of platform distance
    static constexpr int STAGE_ONE = 500;             // Only static platforms show up
    static constexpr int STAGE_TWO = 1500;            // Static and horizontal platforms show up
    static constexpr int STAGE_THREE = 4000;          // Static, horizontal and vertical platforms show up
    static constexpr int STAGE_FOUR = 7000;           // Every type of platform shows up

    // Obstacle configurations
    //-------------------------------------------------------------------------------------

    // Score configurations
    // If specific penalty for a specific platform is required, add it to the penalties map
    // see gameModel::Score.h
    //-------------------------------------------------------------------------------------
    static constexpr int DEFAULT_PENALTY = 5; // Penalty for dubbel jump on platform
};
} // namespace configs

#endif // GAMECONFIG_H
