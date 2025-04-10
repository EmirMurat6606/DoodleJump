/**************************************************************************************************
 * @file Camera.h
 * @brief Camera class declaration, used to represent the movement of the camera in the game
 * @namespace gameModel
 **************************************************************************************************/

#ifndef DOODLE_GAME_CAMERA_H
#define DOODLE_GAME_CAMERA_H

#include "../Configs/GameConfig.h"
#include <memory>

class Entity;
class Player;

namespace gameModel {
class Camera {
private:
    /**
     * Delta value for the camera
     * \n Distance with which entities have to scroll down
     */
    double delta = 0.0;

    /**
     * Height of the camera
     * \n Increases each time doodler jumps higher
     */
    double camera_height = 0.0;

    /**
     * Scale factor for the x values
     */
    static constexpr double scaleX = configs::GameConfig::RES_WIDTH / configs::GameConfig::VIEW_WIDTH;

    /**
     * Scale factor for the y values
     */
    static constexpr double scaleY = configs::GameConfig::RES_HEIGHT / configs::GameConfig::VIEW_HEIGHT;

public:
    /**
     * Default constructor of the Camera class
     */
    Camera() = default;

    /**
     * Destructor of the Camera class
     */
    ~Camera() = default;

    /**
     * Checks if the doodler got to a new hight
     * \n if so, set new difference delta
     * @return boolean true if new hight
     */
    bool newHight(double player_height);

    /**
     * Returns the delta value
     * @return delta value
     */
    [[nodiscard]] double getDelta() const;

    /**
     * Returns the height of the camera
     * @return camera height
     */
    [[nodiscard]] double getHeight() const;

    /**
     * Checks if the entity is out of bounds
     * @param entity_y y value of the entity
     * @return boolean true if out of bounds
     */
    [[nodiscard]] bool outOfBounds(double entity_y) const;

    /**
     * Scales the x and y values of the entity to the screen
     * @param logic_x x value of the entity
     * @param logic_y y value of the entity
     * @return a pair of scaled x and y pixel values
     */
    static std::pair<float, float> scaleToScreen(double logic_x, double logic_y);
};

} // namespace gameModel

#endif // DOODLE_GAME_CAMERA_H
