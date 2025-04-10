/****************************************************************************************************
 * @file BonusGenerator.h
 * @brief Responsible for generating new bonuses in the world
 * @namespace gameControl
 */

#ifndef BONUSGENERATOR_H
#define BONUSGENERATOR_H

#include <memory>
#include <vector>

namespace gameModel {
class AEntityFactory;
class Bonus;
class Platform;
} // namespace gameModel

namespace gameControl {
class BonusGenerator {
    /**
     * Shared pointer to the entity factory
     */
    std::shared_ptr<gameModel::AEntityFactory> entityFactory;

    /**
     * Last platform that was added
     *\n Used by platform bound bonuses
     */
    std::shared_ptr<gameModel::Platform> lastPlatform;

public:
    /**
     * Constructor of the BonusGenerator class
     * @param entity_factory pointer to the entity factory (shared between world and generators)
     */
    explicit BonusGenerator(const std::shared_ptr<gameModel::AEntityFactory>& entity_factory);

    /**
     * Default destructor of the BonusGenerator class
     */
    ~BonusGenerator() = default;

    /**
     * Generates a bonus and couples it to a platform
     * @param bonuses vector of bonuses that is updated
     * @param new_platform the platform to couple the bonus to (usually most recently added platform)
     */
    void generate(std::vector<std::shared_ptr<gameModel::Bonus>>& bonuses,
                  const std::shared_ptr<gameModel::Platform>& new_platform);

private:
    /**
     * Creates a bonus
     * @param x x-coordinate of the bonus
     * @param y y-coordinate of the bonus
     * @param index determines the type of the bonus
     */
    [[nodiscard]] std::shared_ptr<gameModel::Bonus> createBonus(double x, double y, int index) const;
};
} // namespace gameControl

#endif // BONUSGENERATOR_H
