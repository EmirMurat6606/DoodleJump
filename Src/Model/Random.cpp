//
// Created by emir on 11/9/24.
//

#include "Random.h"

gameModel::Random::Random() : rng(std::random_device{}()) {}

gameModel::Random& gameModel::Random::getInstance() {
    static Random _instance{};
    return _instance;
}

int gameModel::Random::randomIndex(const std::vector<int>& weights) { // NOLINT
    std::discrete_distribution<> dist(weights.begin(), weights.end());
    return dist(rng);
}

int gameModel::Random::randomValue(const int a, const int b) {
    std::uniform_int_distribution<int> dist(a, b);
    return dist(rng);
}

double gameModel::Random::randomValue(const double a, const double b) {
    std::uniform_real_distribution<double> dist(a, b);
    return dist(rng);
}
