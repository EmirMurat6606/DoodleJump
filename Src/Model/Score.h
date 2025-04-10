/*****************************************************************************************
 * @file Score.h
 * @brief This file contains the declaration of the Score class which is responsible
 * /n for keeping track of the player's score
 * @namespace gameModel
 *****************************************************************************************/

#ifndef DOODLE_GAME_SCORE_H
#define DOODLE_GAME_SCORE_H

#include <unordered_map>

#include "Bonus.h"
#include "Platform.h"
#include "Subject.h"

namespace gameModel {
class Camera;
}

namespace gameModel {
class Score : public Subject<Score> {

    /**
     * The score of the player
     * \n Initialized to 0
     */
    int score = 0;

    /**
     * The high score of the player
     * \n Initialized to 0
     * \n Save in file HighScore.txt
     */
    int high_score = 0;

    /**
     * Total penalties for the player
     */
    int total_penalties = 0;

    /**
     * Penalty for each platform type
     */
    std::unordered_map<PlatformType, int> penalties = {
        {SPlatform, 10}, // penalty for static platform
        {HPlatform, 5},  // penalty for horizontal platform
        {VPlatform, 5},  // penalty for vertical platform
        {TPlatform, 0}   // dubbel jump impossible
    };

public:
    /**
     * Constructor of the Score class
     */
    Score();

    /**
     * Default destructor of the Score class
     */
    ~Score() override;

    /**
     * return score
     */
    int getScore() const;

    /**
     * return high score
     */
    int getHighScore() const;

    /**
     * Updates the penalties that the player gets
     * @param platform the type of platform the player jumped on multiple times
     * \n Default is used for normal platforms
     */
    void update(PlatformType platform = Default);

    /**
     * Updates the score by observing the camera height
     * @param cam the camera object from which the score is updated
     */
    void update(const Camera& cam);

    /**
     * Resets the score
     * \n Used when new world is created
     */
    void reset();
};
} // namespace gameModel
#endif // DOODLE_GAME_SCORE_H
