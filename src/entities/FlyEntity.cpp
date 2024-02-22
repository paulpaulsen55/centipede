#include "FlyEntity.h"

#include "../TextureManager.h"

FlyEntity::FlyEntity(const int x, const int y, TextureManager &textureManager):
Entity(x, y, textureManager.getTexture("fly"), 10)
{
    sprite.setPosition(x, y);
}

void FlyEntity::move() {

}

void FlyEntity::handleCollision(Entity *other) {

}
