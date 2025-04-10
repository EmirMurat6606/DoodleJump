/*****************************************************************************************
 * @file Stopwatch.h
 * @brief This file contains the declaration of the Stopwatch class
 * @namespace gameModel
 *****************************************************************************************/

#ifndef DOODLE_GAME_STOPWATCH_H
#define DOODLE_GAME_STOPWATCH_H

#include <chrono>

using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;

namespace gameModel {

class Stopwatch {
private:
    /**
     * Default constructor of the Stopwatch class
     */
    Stopwatch() = default;

    /**
     * Default destructor of the Stopwatch class
     */
    ~Stopwatch() = default;

    /**
     * Time of the stopwatch
     * From the start to the end
     */
    TimePoint Time;

public:
    /**
     * Explicitly deleted copy constructor
     */
    Stopwatch(const Stopwatch&) = delete;

    /**
     * Explicitly deleted copy assignment operator
     */
    Stopwatch& operator=(const Stopwatch&) = delete;

    /**
     * Function that returns the unique instance of the Stopwatch class
     * @return Unique instance of the Stopwatch class
     */
    static Stopwatch& getInstance();

    /**
     * Start the stopwatch
     */
    void start();

    /**
     * @return The duration of the stopwatch
     */
    [[nodiscard]] std::chrono::duration<double> getDuration() const;
};

} // namespace gameModel

#endif // DOODLE_GAME_STOPWATCH_H
