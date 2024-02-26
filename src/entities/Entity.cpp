#include "Entity.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "../TextureManager.h"

using namespace sf;

Entity::Entity(const std::string &texture) {
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    TextureManager::getInstance().loadTexture(texture);
    sprite.setTexture(TextureManager::getInstance().getTexture(texture));
}

void Entity::setPosition(const int x, const int y) {
    this->x = x;
    this->y = y;
    sprite.setPosition(x, y);
}

void Entity::setGridPosition(const int gridX, const int gridY) {
    this->gridX = gridX;
    this->gridY = gridY;
}

bool Entity::isAlive() const {
    return lives > 0;
}

void Entity::damage() {
    --lives;
}

void Entity::draw(RenderTarget &target, RenderStates states) const {
    target.draw(sprite);
}

int Entity::getGridX() const {
    return gridX;
}

int Entity::getGridY() const {
    return gridY;
}
