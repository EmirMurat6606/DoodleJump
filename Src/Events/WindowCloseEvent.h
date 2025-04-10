/*********************************************************************************************
 * @file WindowCloseEvent.cpp
 * @brief This class is responsible for handling the window close event
 * @namespace events
 *********************************************************************************************/

#ifndef WINDOWCLOSEEVENT_H
#define WINDOWCLOSEEVENT_H

#include "Event.h"

namespace events {
class WindowCloseEvent : public Event {

    /**
     * Boolean that indicates if the window is closed
     */
    bool windowClosed = false;

public:
    /**
     * Handle the window close event
     * @param event The SFML event
     */
    void handleEvent(const sf::Event& event) override;

    /**
     * Check if the window close event was triggered
     * @return True if the window is closed, false otherwise
     */
    [[nodiscard]] bool isWindowClosed() const;

    /**
     * Reset the window closed flag
     */
    void update() override;
};
} // namespace events

#endif // WINDOWCLOSEEVENT_H
