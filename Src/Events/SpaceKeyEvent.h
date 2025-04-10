/******************************************************************************
 * @file SpaceKeyEvent.h
 * @brief This class is responsible for handling the space key event
 * @namespace events
 ******************************************************************************/

#ifndef SPACEKEYEVENT_H
#define SPACEKEYEVENT_H

#include "Event.h"

namespace events {
class SpaceKeyEvent : public Event {

    /**
     * Boolean that indicates if the space key is pressed
     */
    bool spacePressedEvent = false;

public:
    /**
     * Handle the space key event
     * @param event The SFML event
     */
    void handleEvent(const sf::Event& event) override;

    /**
     * Check if the space key is pressed
     * @return True if the space key is pressed, false otherwise
     */
    [[nodiscard]]
    bool isSpacePressed() const;

    /**
     * Update the space key event
     */
    void update() override;
};
} // namespace events

#endif // SPACEKEYEVENT_H
