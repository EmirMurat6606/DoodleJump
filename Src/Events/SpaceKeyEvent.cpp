//
// Created by emir on 12/27/24.
//

#include "SpaceKeyEvent.h"

void events::SpaceKeyEvent::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        spacePressedEvent = true;
    } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
        spacePressedEvent = false;
    }
}

bool events::SpaceKeyEvent::isSpacePressed() const { return spacePressedEvent; }

void events::SpaceKeyEvent::update() { /* UNUSED */ }
