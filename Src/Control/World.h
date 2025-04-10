/**************************************************************************************
 * @file World.h
 * @brief This file contains the declaration of the World class
 * The World class is responsible for managing all the entities in the game
 * @namespace gameControl
 **************************************************************************************/

#ifndef DOODLE_GAME_WORLD_H
#define DOODLE_GAME_WORLD_H

#include "../Model/AEntityFactory.h"
#include "../Model/Camera.h"
#include "BGTileGenerator.h"
#include "BonusGenerator.h"
#include "PlatformGenerator.h"

#include <memory>
#include <vector>

#include "ObstacleGenerator.h"

/**
 * @enum KeyPress Represents the direction of the key press
 * \n Left - left key press
 * \n Right - right key press
 */
enum KeyPress { Left, Right };

namespace gameControl {
class World {

    /**
     * Vector that stores the static platform entities
     */
    std::vector<std::shared_ptr<gameModel::Platform>> platforms;

    /**
     * Vector that stores the bonus entities
     */
    std::vector<std::shared_ptr<gameModel::Bonus>> bonuses;

    /**
     * Vector that stores the background tile entities
     */
    std::vector<std::shared_ptr<gameModel::BGTile>> bg_tiles;

    /**
     * Vector that stores the obstacle entities
     */
    std::vector<std::shared_ptr<gameModel::Obstacle>> obstacles;

    /**
     * Pointer to the doodler (player)
     */
    std::shared_ptr<gameModel::Player> doodler;

    /**
     * Pointer to the camera
     */
    std::unique_ptr<gameModel::Camera> camera = std::make_unique<gameModel::Camera>();

    /**
     * Unique pointer to the entity factory
     * \n Responsible for creating the entity objects
     */
    std::shared_ptr<gameModel::AEntityFactory> entityFactory;

    /**
     * Unique pointer to the score object
     * \n Holds the score of the player
     */
    std::shared_ptr<gameModel::Score> game_score;

    /**
     * Unique pointer to the background tile generator
     * \n Responsible for generating new background tiles
     */
    std::unique_ptr<BGTileGenerator> bgTileGenerator = std::make_unique<BGTileGenerator>(entityFactory);

    /**
     * Unique pointer to the bonus generator
     * \n Responsible for generating new bonuses
     */
    std::unique_ptr<BonusGenerator> bonusGenerator = std::make_unique<BonusGenerator>(entityFactory);

    /**
     * Unique pointer to the platform generator
     * \n Responsible for generating new platforms
     */
    std::unique_ptr<PlatformGenerator> platformGenerator = std::make_unique<PlatformGenerator>(entityFactory);

    /**
     * Unique pointer to the obstacle generator
     * \n Responsible for generating new obstacles
     */
    std::unique_ptr<ObstacleGenerator> obstacleGenerator = std::make_unique<ObstacleGenerator>(entityFactory);

    /**
     * Boolean variable that indicates if the game is over
     */
    bool game_over = false;

public:
    /**
     * Constructor of the World class
     * @param factory unique pointer to the entity factory for creating entities
     * @param score shared pointer to the score of the game (each new world can update the score)
     */
    explicit World(const std::shared_ptr<gameModel::AEntityFactory>& factory,
                   const std::shared_ptr<gameModel::Score>& score);

    /**
     * Default destructor of the World class
     */
    ~World() = default;

    /**
     * Processes the input get from game class
     * @param deltaTime time between two updates
     */
    void update(double deltaTime);

    /**
     * Returns a boolean variable that indicates if the game is over
     */
    [[nodiscard]] bool isGameOver() const;

    /**
     * Handles the input from the game class
     * @param key key pressed by the player
     * @param delta_time time between two updates
     */
    void handleInput(const KeyPress& key, double delta_time) const;

private:
    /**
     * Detects collisions between player and other entities
     * \n Based on intersecting rectangles (bounding boxes)
     * @param entity the entity to check collision with
     * @return boolean true if collision detected
     */
    [[nodiscard]] bool collisionDetect(const std::shared_ptr<gameModel::Entity>& entity) const;

    /**
     * Updates the platforms in the game
     * @param delta_time the time since the last update
     */
    void updatePlatforms(double delta_time);

    /**
     * Updates the obstacles in the game
     * @param delta_time the time since the last update
     */
    void updateObstacles(double delta_time);

    /**
     * Updates the position of all the entities if camera moves
     * \n Calls generators to generate new entities
     * @param delta_time time between two frame updates
     */
    void updateView(double delta_time);
};
} // namespace gameControl

#endif // DOODLE_GAME_WORLD_H
