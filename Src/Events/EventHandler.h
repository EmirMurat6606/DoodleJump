/*****************************************************************************************
 * @file EventHandler.h
 * @brief Header file for the EventHandler class which is responsible for handling events
 * @namespace events
 *****************************************************************************************/

#ifndef EVENTHANDLER_SFML_H
#define EVENTHANDLER_SFML_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

namespace events {
class Event;

class EventHandler {
    /**
     * Vector that stores the events
     */
    std::vector<std::shared_ptr<Event>> events_;

public:
    /**
     * Constructor of the EventHandler class
     * @param window shared pointer to the game window
     */
    explicit EventHandler(const std::weak_ptr<sf::RenderWindow>& window) {}

    /**
     * Adds a new event to the handler
     */
    void addEvent(std::shared_ptr<Event> event);

    /**
     * Handles the events
     * @param window the game window
     */
    void handleEvents(sf::RenderWindow& window);

    /**
     * Updates the events
     */
    void updateEvents();
};
} // namespace events

#endif // EVENTHANDLER_SFML_H
