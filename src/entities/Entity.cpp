#include "Entity.h"

#include "../Constants.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "../TextureManager.h"

using namespace sf;

Entity::Entity(const std::string &texture) {
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    TextureManager::getInstance().loadTexture(texture);
    sprite.setTexture(TextureManager::getInstance().getTexture(texture));
}

void Entity::setPosition(const int gridX, const int gridY) {
    this->x = gridX * GRID_WIDTH / (GRID_COLS - 1) + 1;
    this->y = gridY * GRID_HEIGHT / (GRID_ROWS - 1) + 1;
    this->gridX = gridX;
    this->gridY = gridY;
    sprite.setPosition(x, y);
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
