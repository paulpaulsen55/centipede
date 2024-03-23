#include "WormSegment.h"
#include "../../Grid.h"


WormSegment::WormSegment(Grid *grid, WormEntity *wormEntity, const std::string &texture): Entity(texture), grid(grid),
    wormEntity(wormEntity) {
}

void WormSegment::updateGridPosition(const int newGridX, const int newGridY) {
    if (gridX == newGridX && gridY == newGridY) {
        return;
    }
    grid->moveEntity(gridX, gridY, newGridX, newGridY);
    setGridPosition(newGridX, newGridY);
}


Vector2i WormSegment::getNextGridPosition() const {
    return {gridX + static_cast<int>(hDirection), gridY};
}

void WormSegment::flipSprite() {
    hDirection = static_cast<HDirection>(-static_cast<int>(hDirection));

    if (hDirection == HDirection::RIGHT) {
        sprite.setOrigin(0, 0);
    } else {
        sprite.setOrigin(sprite.getLocalBounds().width, 0);
    }
    sprite.setScale(sprite.getScale().x * -1, sprite.getScale().y);
}

void WormSegment::setSprite(const std::string &texture) {
    sprite.setTexture(TextureManager::getInstance().getTexture(texture));
}

