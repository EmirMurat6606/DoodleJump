//
// Created by emir on 11/10/24.
//

#include "Score.h"
#include "../Exceptions/FileLoadException.h"
#include <filesystem>
#include <fstream>

#include "Camera.h"

/**
 * The file where the high score is saved
 */
const std::string filename = "../Src/Configs/HighScore.txt";

gameModel::Score::Score() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        exceptions::FileLoadException::fileNotOpened(filename);
    }
    try {
        file >> high_score;
        file.close();
    } catch (const std::exception& e) {
        exceptions::FileLoadException::fileReadError(filename);
    }
}

gameModel::Score::~Score() {
    if (!std::filesystem::exists(filename)) {
        exceptions::FileLoadException::fileWriteError(filename);
    } else {
        try {
            std::ofstream file(filename, std::ios::out | std::ios::trunc);
            file << high_score;
            file.close();
        } catch (const std::exception& e) {
            exceptions::FileLoadException::fileWriteError(filename);
        }
    }
}

int gameModel::Score::getScore() const { return score; }

int gameModel::Score::getHighScore() const { return high_score; }

void gameModel::Score::update(const PlatformType platform) {
    int penalty = 0;
    penalties.find(platform) != penalties.end() ? penalty += penalties[platform]
                                                : penalty += configs::GameConfig::DEFAULT_PENALTY;
    total_penalties += penalty;
    score -= penalty;
    if (score < 0)
        score = 0;
}

void gameModel::Score::update(const Camera& cam) {
    score = static_cast<int>(cam.getHeight()) - total_penalties;
    if (score < 0)
        score = 0;

    if (score > high_score)
        high_score = score;
}

void gameModel::Score::reset() {
    score = 0;
    total_penalties = 0;
}
