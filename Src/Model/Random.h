/**************************************************************************************
 * @file Random.h
 * @brief This file contains the declaration of the Random class for generating random numbers
 * This class follows the singleton pattern
 * @namespace gameModel
 **************************************************************************************/

#ifndef DOODLE_GAME_RANDOM_H
#define DOODLE_GAME_RANDOM_H

#include <random>

namespace gameModel {
class Random {

    /**
     * Random number generator
     */
    std::mt19937 rng;

    /**
     * Constructor of the Random class
     */

    Random();

    /**
     * Default destructor of the Random class
     */
    ~Random() = default;

public:
    /**
     * Explicitly deleted copy constructor
     * \n No copy is allowed
     */
    Random(const Random&) = delete;

    /**
     * Explicitly deleted copy assignment operator
     * \n No copy assignment is allowed
     */
    Random& operator=(const Random&) = delete;

    /**
     * Function that returns the unique instance of the Random class
     */
    static Random& getInstance();

    /**
     * Function that generates a random index given a list of weights
     * \n The indexes go from 0 to weights.size() - 1
     */
    int randomIndex(const std::vector<int>& weights);

    /**
     * Function that generates a random integer between a and b
     */
    int randomValue(int a, int b);

    /**
     * Function that generates a random double between a and b
     */
    double randomValue(double a, double b);
};

} // namespace gameModel

#endif // DOODLE_GAME_RANDOM_H
