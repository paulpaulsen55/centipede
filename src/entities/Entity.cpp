#include "Entity.h"

#include "MushroomEntity.h"
#include "../Constants.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "../TextureManager.h"
#include "../Grid.h"

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

void Entity::draw(RenderTarget &target, RenderStates states) const {
    target.draw(sprite);
}

int Entity::getGridX() const {
    return gridX;
}

int Entity::getGridY() const {
    return gridY;
}

void Entity::updateGridPosition(const int newGridX, const int newGridY) {
    Grid::getInstance().moveEntity(gridX, gridY, newGridX, newGridY);
    gridX = newGridX;
    gridY = newGridY;
    x = gridX * GRID_WIDTH / (GRID_COLS - 1) + 1;
    y = gridY * GRID_HEIGHT / (GRID_ROWS - 1) + 1;
    update();
}

void Entity::setGridPosition(const int newGridX, const int newGridY) {
    gridX = newGridX;
    gridY = newGridY;
    x = gridX * GRID_WIDTH / (GRID_COLS - 1) + 1;
    y = gridY * GRID_HEIGHT / (GRID_ROWS - 1) + 1;
    update();
}
