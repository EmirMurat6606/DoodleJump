/*****************************************************************************************
 * @file Event.h
 * @brief The Event class is responsible for handling sfml events
 * @namespace events
 *****************************************************************************************/

#ifndef EVENT_SFML_H
#define EVENT_SFML_H

#include <SFML/Graphics.hpp>

namespace events {
class Event {

public:
    /**
     * Constructor of the EventHandler class
     */
    Event() = default;

    /**
     * Destructor of the EventHandler class
     */
    virtual ~Event() = default;

    /**
     * Process an event
     * @param event the SFML-event
     */
    virtual void handleEvent(const sf::Event& event) = 0;

    /**
     * Updates the logic
     */
    virtual void update() = 0;
};
}; // namespace events

#endif // EVENT_SFML_H
