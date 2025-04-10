/*****************************************************************************************
 * @file Bonus.h
 * @brief This file contains the declaration of the Bonus class and its derived classes
 * @namespace gameModel
 *****************************************************************************************/

#ifndef DOODLE_GAME_BONUS_H
#define DOODLE_GAME_BONUS_H

#include "Entity.h"

namespace gameModel {
class PlayerState;
class Player;
} // namespace gameModel

/**
 * @enum BonusType Represents the types of bonuses
 * \n Spring - Spring Bonus
 * \n Jetpack - Jetpack Bonus
 */
enum BonusType { Spring, Jetpack };

namespace gameModel {

class Bonus : public Entity {

public:
    /**
     * Constructor of the Bonus class
     */
    Bonus(double x_location, double y_location);

    /**
     * Virtual destructor
     */
    virtual ~Bonus() = default;

    /**
     * Inherited from the Entity class
     */
    [[nodiscard]] virtual BonusType getType() const = 0;

    /**
     * Passes a new state to the player
     * \n Inherited only if the bonus has a special effect
     */
    virtual void apply(Player& player) const;
};

// Spring Bonus
class SpringBonus : public Bonus {
public:
    /**
     * Constructor of the SpringBonus class
     */
    SpringBonus(double x_location, double y_location);

    /**
     * Default destructor of the SpringBonus class
     */
    ~SpringBonus() override = default;

    /**
     * Get spring bonus type
     */
    [[nodiscard]] BonusType getType() const override;

    /**
     * Applies the spring state to the player
     */
    void apply(Player& player) const override;
};

// Jetpack Bonus
class JetpackBonus : public Bonus {

public:
    /**
     * Constructor of the JetpackBonus class
     */
    JetpackBonus(double x_location, double y_location);

    /**
     * Default destructor of the JetpackBonus class
     */
    ~JetpackBonus() override = default;

    /**
     * Get jetpack bonus type
     */
    [[nodiscard]] BonusType getType() const override;

    /**
     * Applies the jetpack state to the player
     */
    void apply(Player& player) const override;
};
} // namespace gameModel

#endif // DOODLE_GAME_BONUS_H
