//
// Created by emir on 11/9/24.
//

#include "Stopwatch.h"

gameModel::Stopwatch& gameModel::Stopwatch::getInstance() {
    static Stopwatch _instance{};
    return _instance;
}

void gameModel::Stopwatch::start() { Time = std::chrono::steady_clock::now(); }

std::chrono::duration<double> gameModel::Stopwatch::getDuration() const {
    return std::chrono::steady_clock::now() - Time;
}
