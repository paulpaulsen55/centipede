#include "FlyEntity.h"

#include "MushroomEntity.h"
#include "../Grid.h"
#include "../UtilityFunctions.h"

FlyEntity::FlyEntity(Grid *grid): Entity("assets/entities/fly.png"), grid(grid) {
}

void FlyEntity::move(const float dt) {
    this->moveDt += dt;

    if (moveDt > speed) {
        moveDt = 0;

        updateGridPosition(gridX, gridY + 1);

        if (getGridY() == GRID_ROWS - 1) {
            lives = 0;
        }
        if (generateRandomNumber(0, 100) < 20) {
            grid->placeEntity(gridX, gridY - 1, std::make_unique<MushroomEntity>());
        }
    }
}

void FlyEntity::handleCollision(Entity *other) {
    if (dynamic_cast<MushroomEntity *>(other) != nullptr) {
        updateGridPosition(gridX, gridY + 1);
    }
}

void FlyEntity::updateGridPosition(const int newGridX, const int newGridY) {
    grid->moveEntity(gridX, gridY, newGridX, newGridY);
    setGridPosition(newGridX, newGridY);
}

Vector2i FlyEntity::getNextGridPosition() const {
    return {gridX, gridY + 1};
}
