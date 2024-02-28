#include "FlyEntity.h"

#include "MushroomEntity.h"
#include "../TextureManager.h"
#include "../Grid.h"
#include "../UtilityFunctions.h"

FlyEntity::FlyEntity(): Entity("assets/fly.png") {
}

void FlyEntity::move(const float dt) {
    this->moveDt += dt;

    if (moveDt > speed) {
        moveDt = 0;


        updateGridPosition(gridX, gridY+1);
        //update();

        if (getGridY() == GRID_ROWS - 1) {
            lives = 0;
        }
        if (generateRandomNumber(0, 100) < 20) {
            printf("Mushroom\n");
            //Grid::getInstance().placeEntity(0, 0, std::make_unique<MushroomEntity>());
        }
    }
}

void FlyEntity::handleCollision(Entity *other) {
}
