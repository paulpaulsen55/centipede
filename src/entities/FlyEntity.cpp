#include "FlyEntity.h"

#include "../TextureManager.h"

FlyEntity::FlyEntity(const int x, const int y, const Texture &texture): Entity(
    x, y, texture, 10) {
    this->lives = 2;
}

void FlyEntity::move() {
}

void FlyEntity::handleCollision(Entity *other) {
}
