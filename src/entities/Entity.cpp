#include "Entity.h"

#include "SFML/Graphics/RenderTarget.hpp"

using namespace sf;

Entity::Entity(const int x, const int y, const Texture &texture, const float speed):
    x(x),
    y(y),
    speed(speed)
{
    sprite.setTexture(texture);
}

void Entity::draw(RenderTarget &target, RenderStates states) const {
    target.draw(sprite);
}
