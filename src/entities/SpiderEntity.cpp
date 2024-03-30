#include "SpiderEntity.h"

#include <cmath>

#ifdef _MSC_VER
#include <corecrt_math_defines.h>
#endif

#include "MushroomEntity.h"
#include "../Grid.h"
#include "../UtilityFunctions.h"

SpiderEntity::SpiderEntity(const int startingGridX, Grid *grid): Entity("assets/entities/spider.png"),
                                                                 grid(grid),
                                                                 startingGridX(startingGridX) {
    speed = static_cast<float>(generateRandomNumber(3, 15)) * 0.1f;
}

void SpiderEntity::move(const float dt) {
    this->moveDt += dt;

    if (moveDt > speed) {
        moveDt = 0;

        if (const float offset = 2 * static_cast<float>(std::sin(M_PI_4 * gridY)); offset > 0) {
            updateGridPosition(startingGridX + static_cast<int>(std::floor(offset)), gridY + 1);
        } else {
            updateGridPosition(startingGridX + static_cast<int>(std::ceil(offset)), gridY + 1);
        }

        if (gridY == GRID_ROWS - 1) {
            lives = 0;
        }
    }
}

void SpiderEntity::handleCollision(Entity *other) {
    if (dynamic_cast<MushroomEntity *>(other) != nullptr) {
        move(5.0);
    }
}

void SpiderEntity::updateGridPosition(const int newGridX, const int newGridY) {
    grid->moveEntity(gridX, gridY, newGridX, newGridY);
    setGridPosition(newGridX, newGridY);
}

Vector2i SpiderEntity::getNextGridPosition() const {
    return {gridX, gridY + 1}; // inaccuracy: the spider moves in a sinusoidal pattern
}
