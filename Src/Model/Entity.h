/*****************************************************************************************
 * @file Entity.h
 * This file contains the declaration of the Entity class
 * The Entity class is the base class for all entities in the game
 * @namespace gameModel
 *****************************************************************************************/

#ifndef DOODLE_GAME_ENTITY_H
#define DOODLE_GAME_ENTITY_H

#include "Subject.h"

namespace gameModel {
class Entity : public Subject<Entity> {

protected:
    /**
     * x_location of the entity
     * from bottom left corner
     */
    double x_location;

    /**
     * y_location of the entity
     * from bottom left corner
     */
    double y_location;

    /**
     * width of the entity
     */
    double width = 0;

    /**
     * height of the entity
     */
    double height = 0;

public:
    /**
     * Default constructor of the Entity class
     */
    explicit Entity(double x_location, double y_location);

    /**
     * Virtual destructor of the Entity class
     */
    virtual ~Entity() = default;

    /**
     * Setter for the x_location
     * @param delta_x the change in x_location
     */
    virtual void updateX(double delta_x);

    /**
     * Setter for the y_location
     * @param delta_y the change in y_location
     */
    virtual void updateY(double delta_y);

    /**
     * Getter for the minimum x_location of the entity
     */
    [[nodiscard]] double x_Min() const;

    /**
     * Getter for the maximum x_location of the entity
     */
    [[nodiscard]] double x_Max() const;

    /**
     * Getter for the minimum y_location of the entity
     */
    [[nodiscard]] double y_Min() const;

    /**
     * Getter for the maximum y_location of the entity
     */
    [[nodiscard]] double y_Max() const;

    /**
     * Sets the x location of the entity
     * @param x_location a value in range of the screen width and > 0
     */
    void setX(double x_location);

    /**
     * Sets the y location of the entity
     * @param y_location a value in range of the screen height and > 0
     */
    void setY(double y_location);

    /**
     * Virtual function
     * Updates the entity position per update
     * @attention Static entities should not override this function
     * @param delta_time time between two updates
     */
    virtual void update(double delta_time);
};
}; // namespace gameModel
   // namespace gameModel

#endif // DOODLE_GAME_ENTITY_H
