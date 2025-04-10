//
// Created by emir on 12/27/24.
//

#include "WindowCloseEvent.h"

namespace events {

void WindowCloseEvent::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        windowClosed = true;
    }
}

bool WindowCloseEvent::isWindowClosed() const { return windowClosed; }

void WindowCloseEvent::update() { /* UNUSED */ }

} // namespace events
