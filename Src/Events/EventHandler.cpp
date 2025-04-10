//
// Created by emir on 12/27/24.
//

#include "EventHandler.h"
#include "Event.h"

void events::EventHandler::addEvent(std::shared_ptr<Event> handler) { events_.push_back(std::move(handler)); }

void events::EventHandler::handleEvents(sf::RenderWindow& window) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        for (const auto& specified_event : events_) {
            specified_event->handleEvent(event);
        }
    }
}

void events::EventHandler::updateEvents() {
    for (const auto& event : events_) {
        event->update();
    }
}
