/*************************************************************************
 * @file BonusView.h
 * @brief This file contains the declaration of the BonusGUI class
 * @namespace gameView
 *************************************************************************/

#ifndef BONUSGUI_SFML_H
#define BONUSGUI_SFML_H

#include "EntityView.h"

namespace gameView {
class BonusView : public EntityView {
public:
    /**
     * Constructor of the BonusView
     * @param game_window weak pointer to the main game window
     */
    explicit BonusView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Default destructor of the BonusView
     */
    ~BonusView() override = default;
};

class JetpackBonusView : public BonusView {
public:
    /**
     * Constructor of the JetpackBonusView class
     */
    explicit JetpackBonusView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Destructor of the JetpackBonusView class
     */
    ~JetpackBonusView() override = default;
};

class SpringBonusView : public BonusView {
public:
    /**
     * Constructor of the SpringBonusView class
     */
    explicit SpringBonusView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Destructor of the SpringBonusView class
     */
    ~SpringBonusView() override = default;
};
} // namespace gameView

#endif // BONUSGUI_SFML_H
