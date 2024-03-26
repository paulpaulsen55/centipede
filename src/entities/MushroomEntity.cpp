#include "MushroomEntity.h"

#include "../TextureManager.h"

MushroomEntity::MushroomEntity(): Entity("assets/entities/mushroom3.png") {
    this->lives = 3;
    // also load other texture variants
    TextureManager::getInstance().loadTexture("assets/entities/mushroom2.png");
    TextureManager::getInstance().loadTexture("assets/entities/mushroom1.png");
}

void MushroomEntity::handleCollision(Entity *other) {
}

void MushroomEntity::damage() {
    --lives;
    if (lives == 2) {
        sprite.setTexture(TextureManager::getInstance().getTexture("assets/entities/mushroom2.png"));
    } else if (lives == 1) {
        sprite.setTexture(TextureManager::getInstance().getTexture("assets/entities/mushroom1.png"));
    }
}
