/*************************************************************************
 * @file EntityView.h
 * @brief This file contains the graphical representation of the entities
 * @namespace gameView
 ************************************************************************/

#ifndef ENTITYVIEW_H
#define ENTITYVIEW_H

#include "../Model/Observer.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace gameModel {
class Entity;
}

namespace gameView {
class EntityView : public gameModel::Observer<gameModel::Entity> {
protected:
    /**
     * Weak pointer to the game_window
     */
    std::weak_ptr<sf::RenderWindow> game_window;

    /**
     * Sprite of the entity
     */
    sf::Sprite entity_sprite = sf::Sprite();

    /**
     * Draws the entity view on the screen
     */
    virtual void draw() const;

public:
    /**
     * Constructor of the EntityView
     * @param game_window weak pointer to the main game window
     */
    explicit EntityView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Destructor of the EntityView
     */
    ~EntityView() override = default;

    /**
     * Updates the entity view
     * \n Can be overridden by the derived classes
     */
    virtual void update(const gameModel::Entity& entity);
};
} // namespace gameView

#endif // ENTITYVIEW_H
