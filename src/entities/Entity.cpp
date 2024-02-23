#include "Entity.h"

#include "SFML/Graphics/RenderTarget.hpp"

using namespace sf;

Entity::Entity(const int x, const int y, const Texture &texture, const float speed):
    x(x),
    y(y),
    speed(speed)
{
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    sprite.setTexture(texture);
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
