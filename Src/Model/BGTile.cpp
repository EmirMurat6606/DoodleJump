//
// Created by emir on 11/9/24.
//

#include "BGTile.h"

gameModel::BGTile::BGTile(const double x_location, const double y_location) : Entity(x_location, y_location) {
    width = tileWidth;
    height = tileHeight;
}
