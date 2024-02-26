#include "FlyEntity.h"

#include "../TextureManager.h"

FlyEntity::FlyEntity(const int x, const int y): Entity(x, y, "assets/fly.png", 10) {
    this->lives = 2;
}

void FlyEntity::move() {
}

void FlyEntity::handleCollision(Entity *other) {
}
