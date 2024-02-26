#include "MushroomEntity.h"

#include "../TextureManager.h"

MushroomEntity::MushroomEntity(const int x, const int y): Entity(x, y, "assets/mushroom3.png", 0) {
    this->lives = 3;
    // load other texture variants
    TextureManager::getInstance().loadTexture("assets/mushroom2.png");
    TextureManager::getInstance().loadTexture("assets/mushroom1.png");
}

void MushroomEntity::move() {
}

void MushroomEntity::handleCollision(Entity *other) {
}

void MushroomEntity::damage() {
    --lives;
    if (lives == 2) {
        sprite.setTexture(TextureManager::getInstance().getTexture("assets/mushroom2.png"));
    } else if (lives == 1) {
        sprite.setTexture(TextureManager::getInstance().getTexture("assets/mushroom1.png"));
    }
}
