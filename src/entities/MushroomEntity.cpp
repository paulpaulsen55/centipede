#include "MushroomEntity.h"

MushroomEntity::MushroomEntity(const int x, const int y): Entity(x, y, "assets/mushroom.png", 0) {
    this->lives = 3;
}

void MushroomEntity::move() {
}

void MushroomEntity::handleCollision(Entity *other) {
}
