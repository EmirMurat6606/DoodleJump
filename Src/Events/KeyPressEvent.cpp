//
// Created by emir on 12/27/24.
//

#include "KeyPressEvent.h"

void events::KeyPressHandler::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            leftKeyPressed = true;
            keyPressedEvent = true;
            LeftEvent = true;
        } else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            rightKeyPressed = true;
            keyPressedEvent = true;
            LeftEvent = false;
        }
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            leftKeyPressed = false;
        } else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            rightKeyPressed = false;
        }
    }
}

void events::KeyPressHandler::update() {
    if (!leftKeyPressed && rightKeyPressed) {
        keyPressedEvent = true;
        LeftEvent = false;
    } else if (leftKeyPressed && !rightKeyPressed) {
        keyPressedEvent = true;
        LeftEvent = true;
    } else if (!leftKeyPressed && !rightKeyPressed) {
        keyPressedEvent = false;
    }
}

bool events::KeyPressHandler::isKeyPressed() const { return keyPressedEvent; }

bool events::KeyPressHandler::isLeft() const { return LeftEvent; }
