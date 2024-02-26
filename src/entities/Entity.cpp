#include "Entity.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "../TextureManager.h"

using namespace sf;

Entity::Entity(const int x, const int y, const std::string &texture, const float speed):
    x(x),
    y(y),
    speed(speed)
{
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    TextureManager::getInstance().loadTexture(texture);
    sprite.setTexture(TextureManager::getInstance().getTexture(texture));
}

void Entity::draw(RenderTarget &target, RenderStates states) const {
    target.draw(sprite);
}

void Entity::setPosition(const int x, const int y) {
    this->x = x;
    this->y = y;
    sprite.setPosition(x, y);
}

bool Entity::isAlive() const {
    return lives > 0;
}

void Entity::damage() {
    --lives;
}
