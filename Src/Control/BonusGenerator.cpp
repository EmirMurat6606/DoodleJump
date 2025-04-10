//
// Created by emir on 12/2/24.
//

#include "BonusGenerator.h"

#include "../Configs/GameConfig.h"
#include "../Model/AEntityFactory.h"
#include "../Model/Bonus.h"
#include "../Model/Random.h"

gameControl::BonusGenerator::BonusGenerator(const std::shared_ptr<gameModel::AEntityFactory>& entity_factory)
    : entityFactory(entity_factory), lastPlatform(nullptr) {}

void gameControl::BonusGenerator::generate(std::vector<std::shared_ptr<gameModel::Bonus>>& bonuses,
                                           const std::shared_ptr<gameModel::Platform>& new_platform) {

    // If the platform already has a bonus
    //-------------------------------------
    if (new_platform->getBonus() || new_platform.get() == lastPlatform.get())
        return;

    lastPlatform = new_platform;
    const int random = gameModel::Random::getInstance().randomValue(0, 100);

    // x% chance for a bonus
    //--------------------------------
    if (random > configs::GameConfig::BONUS_PROB)
        return;

    // Bonus has to be generated
    //--------------------------------
    const std::vector<int> weights = {
        configs::GameConfig::SPRING_PROB, // 70% chance for a SpringBonus
        configs::GameConfig::JETPACK_PROB // 30% chance for a JetPackBonus
    };
    constexpr double x_offset = configs::GameConfig::PLATFORM_WIDTH / 5.0;
    const double x = gameModel::Random::getInstance().randomValue(new_platform->x_Min() + x_offset,
                                                                  new_platform->x_Max() - x_offset);
    const double y = new_platform->y_Max();
    const auto bonus = createBonus(x, y, gameModel::Random::getInstance().randomIndex(weights));
    bonuses.push_back(bonus);
    new_platform->attachBonus(bonus);
}

std::shared_ptr<gameModel::Bonus> gameControl::BonusGenerator::createBonus(const double x, const double y,
                                                                           const int index) const {
    switch (index) {
    case 0:
        return entityFactory->createBonus(x, y, Spring);
    case 1:
        return entityFactory->createBonus(x, y, Jetpack);
    default:
        return entityFactory->createBonus(x, y, Spring);
    }
}
