#include "MushroomEntity.h"

MushroomEntity::MushroomEntity(const int x, const int y, const Texture &texture): Entity(x, y, texture, 0) {
    this->lives = 3;
}

void MushroomEntity::move() {
}

void MushroomEntity::handleCollision(Entity *other) {
}
