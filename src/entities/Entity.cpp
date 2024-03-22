#include "Entity.h"

#include "MushroomEntity.h"
#include "../Constants.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "../TextureManager.h"

using namespace sf;

Entity::Entity(const std::string &texture) {
    sprite.setPosition(x, y);
    TextureManager::getInstance().loadTexture(texture);
    sprite.setTexture(TextureManager::getInstance().getTexture(texture));
}

void Entity::update() {
    sprite.setPosition(x, y);
}

bool Entity::isAlive() const {
    return lives > 0;
}

void Entity::damage() {
    --lives;
}

int Entity::getGridX() const {
    return gridX;
}

int Entity::getGridY() const {
    return gridY;
}

Vector2i Entity::getGridPosition() const {
    return Vector2i(gridX, gridY);
}

void Entity::setGridPosition(const int newGridX, const int newGridY) {
    gridX = newGridX;
    gridY = newGridY;
    x = gridX * GRID_WIDTH / GRID_COLS + 2;
    y = gridY * GRID_HEIGHT / GRID_ROWS + 2;
    update();
}

void Entity::draw(RenderTarget &target, RenderStates states) const {
    target.draw(sprite);
}
