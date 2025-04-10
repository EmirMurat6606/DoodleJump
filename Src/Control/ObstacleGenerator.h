/*****************************************************************************************
 * @file ObstacleGenerator.h
 * @brief Responsible for generating new obstacles in the world
 * @namespace gameControl
 *****************************************************************************************/

#ifndef OBSTACLEGENERATOR_H
#define OBSTACLEGENERATOR_H

#include <memory>
#include <vector>

namespace gameModel {
class AEntityFactory;
class Obstacle;
} // namespace gameModel

namespace gameControl {
class ObstacleGenerator {

    /**
     * Shared pointer to the entity factory
     */
    std::shared_ptr<gameModel::AEntityFactory> entityFactory;

public:
    /**
     * Constructor of the ObstacleGenerator class
     * @param factory pointer to the entity factory (shared between world and generators)
     */
    explicit ObstacleGenerator(const std::shared_ptr<gameModel::AEntityFactory>& factory);

    /**
     * Default destructor of the ObstacleGenerator class
     */
    ~ObstacleGenerator() = default;

    /**
     * Generates new obstacles
     * @param obstacles vector of obstacles
     * @param height the height of the camera view
     * @param delta_time time between two frame updates
     */
    void generate(std::vector<std::shared_ptr<gameModel::Obstacle>>& obstacles, int height, double delta_time) const;

private:
    /**
     * Creates an obstacle
     * @param x x-coordinate of the obstacle
     * @param y y-coordinate of the obstacle
     * @param index determines the type of the obstacle
     */
    [[nodiscard]] std::shared_ptr<gameModel::Obstacle> createObstacle(double x, double y, int index) const;
};
} // namespace gameControl

#endif // OBSTACLEGENERATOR_H
