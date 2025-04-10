//
// Created by emir on 11/9/24.
//

#include "Entity.h"

gameModel::Entity::Entity(const double x_location, const double y_location)
    : x_location(x_location), y_location(y_location) {}

void gameModel::Entity::updateX(const double delta_x) { this->x_location += delta_x; }

void gameModel::Entity::updateY(const double delta_y) { this->y_location += delta_y; }

double gameModel::Entity::x_Min() const { return x_location; }

double gameModel::Entity::x_Max() const { return x_location + width; }

double gameModel::Entity::y_Min() const { return y_location; }

double gameModel::Entity::y_Max() const { return y_location + height; }

void gameModel::Entity::setX(double x_location) { this->x_location = x_location; }

void gameModel::Entity::setY(double y_location) { this->y_location = y_location; }

void gameModel::Entity::update(double delta_time) { /* Do nothing */ }
