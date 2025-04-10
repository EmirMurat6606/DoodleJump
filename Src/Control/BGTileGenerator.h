/*************************************************************************
 * @file BGTileGenerator.h
 * @brief Generates new background tiles
 * @namespace gameModel
 *************************************************************************/

#ifndef BGTILEGENERATOR_H
#define BGTILEGENERATOR_H

#include <memory>
#include <vector>

namespace gameModel {
class AEntityFactory;
class BGTile;
} // namespace gameModel

namespace gameControl {
class BGTileGenerator {
    /**
     * Shared pointer to the entity factory
     */
    std::shared_ptr<gameModel::AEntityFactory> entity_factory;

public:
    /**
     * Constructor of the BGTileGenerator class
     * @param factory pointer to the entity factory (shared between world and generators)
     */
    explicit BGTileGenerator(const std::shared_ptr<gameModel::AEntityFactory>& factory);

    /**
     * Default destructor of the BGTileGenerator class
     */
    ~BGTileGenerator() = default;

    /**
     * Generates new background tiles
     * @param tiles vector of background tiles
     */
    void generate(std::vector<std::shared_ptr<gameModel::BGTile>>& tiles) const;
};
} // namespace gameControl

#endif // BGTILEGENERATOR_H
