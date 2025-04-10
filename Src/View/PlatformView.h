/*********************************************************************************
 * @file PlatformView.h
 * @brief Class that contains graphical representation of the platforms
 * @namespace gameView
 *********************************************************************************/

#ifndef PLATFORMGUI_SFML_H
#define PLATFORMGUI_SFML_H

#include "EntityView.h"

namespace gameView {
class PlatformView : public EntityView {
public:
    /**
     * Constructor of the PlatformGUI class
     */
    explicit PlatformView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Default destructor of the PlatformGUI class
     */
    virtual ~PlatformView() = default;
};

class StaticPlatformView : public PlatformView {
public:
    /**
     * Constructor of the StaticPlatformGUI class
     */
    explicit StaticPlatformView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Default destructor of the StaticPlatformGUI class
     */
    ~StaticPlatformView() override = default;
};

// Horizontal Platform
class HorizontalPlatformView : public PlatformView {
public:
    /**
     * Constructor of the HorizontalPlatformGUI class
     */
    explicit HorizontalPlatformView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Default destructor of the HorizontalPlatformGUI class
     */
    ~HorizontalPlatformView() override = default;
};

// Vertical Platform
class VerticalPlatformView : public PlatformView {
public:
    /**
     * Constructor of the VerticalPlatformGUI class
     */
    explicit VerticalPlatformView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Default destructor of the VerticalPlatformGUI class
     */
    ~VerticalPlatformView() override = default;
};

// Temporary Platform
class TemporaryPlatformView : public PlatformView {
public:
    /**
     * Constructor of the TemporaryPlatformGUI class
     */
    explicit TemporaryPlatformView(const std::weak_ptr<sf::RenderWindow>& game_window);

    /**
     * Default destructor of the TemporaryPlatformGUI class
     */
    ~TemporaryPlatformView() override = default;
};
} // namespace gameView

#endif // PLATFORMGUI_SFML_H
