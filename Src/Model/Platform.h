/*****************************************************************************************
 * @file Entity.h
 * @brief This file contains the declaration of the Platform superclass and its subclasses
 * @namespace gameModel
 *****************************************************************************************/

#ifndef DOODLE_GAME_PLATFORM_H
#define DOODLE_GAME_PLATFORM_H

#include "Bonus.h"
#include "Entity.h"

/**
 * @enum PlatformType Represents the different types of platforms
 * \n Default - default value (useful for functions where type not always needed)
 * \n SPlatform - static platform
 * \n HPlatform - horizontal moving platform
 * \n VPlatform - vertical moving platform
 * \n TPlatform - temporary platform
 */
enum PlatformType { Default, SPlatform, HPlatform, VPlatform, TPlatform };

class Player;
class Bonus;

namespace gameModel {

class Platform : public Entity {

protected:
    /**
     * The bonus on the platform
     */
    std::shared_ptr<Bonus> bonus;

    /**
     * Check if the platform is jumped on
     * \n useful for score penalty
     */
    bool jumped = false;

public:
    /**
     * Constructor of the Platform class
     */
    Platform(double x_location, double y_location);

    /**
     * Destructor of the Platform class
     */
    ~Platform() override = default;

    /**
     * Check if the platform is already jumped on
     */
    [[nodiscard]] bool isJumped() const;

    /**
     * Attach a bonus to the platform
     * @param bonus the bonus to attach
     */
    void attachBonus(const std::shared_ptr<Bonus>& bonus);

    /**
     * Platform is jumped on
     */
    void jump();

    /**
     * Get the bonus of the platform
     */
    [[nodiscard]] std::shared_ptr<gameModel::Bonus> getBonus() const;

    /**
     * Inherited from the Entity class
     */
    [[nodiscard]] virtual PlatformType getType() const = 0;
};

class MovingPlatform : public Platform {
protected:
    /**
     * The horizontal direction of the platform
     * \n true = left
     * \n false = right
     */
    bool direction = false;

    /**
     * Check and update the direction of the platform
     */
    virtual void checkDirection() = 0;

public:
    /**
     * Constructor of the MovingPlatform class
     */
    MovingPlatform(double x_location, double y_location);

    /**
     * Destructor of the MovingPlatform class
     */
    virtual ~MovingPlatform() = default;

    /**
     * Update the platform position continuously
     */
    virtual void update(double delta_time) = 0;

    /**
     * Get the direction of the platform
     */
    [[nodiscard]] bool getDirection() const;
};

// Static Platform
class StaticPlatform : public Platform {
public:
    /**
     * Constructor of the StaticPlatform class
     */
    StaticPlatform(double x_location, double y_location);

    /**
     * Destructor of the StaticPlatform class
     */
    ~StaticPlatform() override = default;

    /**
     * Get the type of the entity
     */
    [[nodiscard]] PlatformType getType() const override;
};

// Horizontal Platform
class HorizontalPlatform : public MovingPlatform {
    /**
     * Check and update the direction of the platform
     */
    void checkDirection() override;

    /**
     * Speed of horizontally moving platforms
     */
    static constexpr double horizontalSpeed = 30;

public:
    /**
     * Constructor of the HorizontalPlatform class
     */
    HorizontalPlatform(double x_location, double y_location);

    /**
     * Destructor of the HorizontalPlatform class
     */
    ~HorizontalPlatform() override = default;

    /**
     * Get the type of the entity
     */
    [[nodiscard]] PlatformType getType() const override;

    /**
     * Overwrites the update function of the Entity class
     * \n Updates the x-position of the platform continuously
     */
    void update(double delta_time) override;
};

// Vertical Platform
class VerticalPlatform : public MovingPlatform {
    /**
     * The original y-position of the platform
     */
    double original_y_pos;

    /**
     * Check and update the direction of the platform
     */
    void checkDirection() override;

    /**
     * Speed of vertically moving platforms
     */
    static constexpr double verticalSpeed = 15;

    /**
     * Range of vertically moving platforms
     */
    static constexpr double range = 40;

public:
    /**
     * Constructor of the VerticalPlatform class
     */
    VerticalPlatform(double x_location, double y_location);

    /**
     * Destructor of the VerticalPlatform class
     */
    ~VerticalPlatform() override = default;

    /**
     * Get the type of the entity
     */
    [[nodiscard]] PlatformType getType() const override;

    /**
     * Overwrites the update function of the Entity class
     * \n Updates the y-position of the platform continuously
     */
    void update(double delta_time) override;

    /**
     * Overwrites the updateY function of the Entity class
     * \n Updates the y-position and the original y-position of the platform
     */
    void updateY(double delta_y) override;
};

// Temporary Platform
class TemporaryPlatform : public Platform {
public:
    /**
     * Constructor of the TemporaryPlatform class
     */
    TemporaryPlatform(double x_location, double y_location);

    /**
     * Destructor of the TemporaryPlatform class
     */
    ~TemporaryPlatform() override = default;

    /**
     * Get the type of the entity
     */
    [[nodiscard]] PlatformType getType() const override;
};

} // namespace gameModel

#endif // DOODLE_GAME_PLATFORM_H
