/***************************************************************************************
 * @file KeyPressEvent.h
 * @brief Class that handles key press events that determine the movement of the player
 * @namespace events
 **************************************************************************************/

#ifndef KEYPRESSEVENT_SFML_H
#define KEYPRESSEVENT_SFML_H

#include "Event.h"
namespace events {
class KeyPressHandler : public Event {

    /**
     * Boolean that indicates if the left key is pressed
     */
    bool leftKeyPressed = false;

    /**
     * Boolean that indicates if the right key is pressed
     */
    bool rightKeyPressed = false;

    /**
     * Boolean that indicates direction of the event
     * \n if true, the event is left
     */
    bool LeftEvent = false;

    /**
     * Boolean that indicates if a key is pressed
     */
    bool keyPressedEvent = false;

public:
    /**
     * Handle the key press event
     * @param event The SFML event
     */
    void handleEvent(const sf::Event& event) override;

    /**
     * Update the key press event
     */
    void update() override;

    /**
     * Check if a key is pressed
     * @return True if a key is pressed, false otherwise
     */
    [[nodiscard]] bool isKeyPressed() const;

    /**
     * Check if the input direction is left or right
     * @return True if left, false otherwise
     */
    [[nodiscard]] bool isLeft() const;
};
} // namespace events

#endif // KEYPRESSEVENT_H
