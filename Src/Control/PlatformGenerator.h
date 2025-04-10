/*************************************************************************
 * @file PlatformGenerator.h
 * @brief Responsible for generating new platforms in het world
 * @namespace gameControl
 *************************************************************************/

#ifndef PLATFORMGENERATOR_H
#define PLATFORMGENERATOR_H

#include "../Model/Platform.h"
#include "BonusGenerator.h"
#include <memory>
#include <vector>

namespace gameModel {
class AEntityFactory;
class Score;
} // namespace gameModel

namespace gameControl {
class PlatformGenerator {

    /**
     * Shared pointer to the entity factory
     */
    std::shared_ptr<gameModel::AEntityFactory> entityFactory;

public:
    /**
     * Constructor of the PlatformGenerator class
     * @param factory pointer to the entity factory (shared between world and generators)
     */
    explicit PlatformGenerator(const std::shared_ptr<gameModel::AEntityFactory>& factory);

    /**
     * Default destructor of the PlatformGenerator class
     */
    ~PlatformGenerator() = default;

    /**
     * Generates new platforms
     * @param platforms vector of platforms
     * @param score the score of the player
     */
    void generate(std::vector<std::shared_ptr<gameModel::Platform>>& platforms, int score) const;

private:
    /**
     * Creates a platform
     * @param x x-coordinate of the platform
     * @param y y-coordinate of the platform
     * @param index determines the type of the platform
     */
    std::shared_ptr<gameModel::Platform> createPlatform(double x, double y, int index) const;
};

} // namespace gameControl

#endif // PLATFORMGENERATOR_H
