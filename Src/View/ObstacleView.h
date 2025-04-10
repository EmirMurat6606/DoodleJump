/*****************************************************************************************
 * @file ObstacleView.h
 * @brief Class that contains graphical representation of the obstacles
 * @namespace gameView
 *****************************************************************************************/

#ifndef OBSTACLEGUI_SFML_H
#define OBSTACLEGUI_SFML_H

#include "EntityView.h"

namespace gameView {
class ObstacleView : public EntityView {
public:
    /**
     * Constructor of the ObstacleView class
     */
    explicit ObstacleView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Default destructor of the ObstacleView class
     */
    virtual ~ObstacleView() = default;
};

// Black Hole
class BlackHoleObstacleView : public ObstacleView {
public:
    /**
     * Constructor of the BlackHoleObstacleView class
     */
    explicit BlackHoleObstacleView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Default destructor of the BlackHoleObstacleView class
     */
    ~BlackHoleObstacleView() override = default;
};

} // namespace gameView

#endif // OBSTACLEGUI_SFML_H
