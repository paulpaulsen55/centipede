#include "WormEntity.h"

#include "../MushroomEntity.h"


WormEntity::WormEntity(Grid *grid): Entity("assets/wormhead.png"), grid(grid) {
    segments.reserve(6);
    segments.push_back(WormSegment(grid, "assets/wormback.png"));
    for (int i = 0; i < 4; ++i) {
        segments.push_back(WormSegment(grid, "assets/wormbody.png"));
    }
    segments.push_back(WormSegment(grid, "assets/wormhead.png"));

    for (int i = 0; i < segments.size(); i++) {
        printf("aa");
        grid->placeEntity(i, gridY, std::make_unique<WormSegment>(segments[i]));
    }
}

void WormEntity::move(const float dt) {
    this->moveDt += dt;

    /*if (moveDt > speed) {
        moveDt = 0;

        int oldGridX = segments[0].getGridX();
        int oldGridY = segments[0].getGridY();


        segments[0].updateGridPosition(gridX + (1 * static_cast<int>(hDirection)), gridY);

        if (gridX <= 0 || gridX >= GRID_COLS || checkForObstacle()) {
            segments[0].updateGridPosition(gridX, gridY + 1);
            hDirection = static_cast<HDirection>(-static_cast<int>(hDirection));
        }

        for (int i = 1; i < segments.size(); i++) {
            printf("oldGridX: %d, oldGridY: %d\n", oldGridX, oldGridY);
            const int tempGridX = segments[i].getGridX();
            const int tempGridY = segments[i].getGridY();
            segments[i].setGridPosition(oldGridX, oldGridY);
            oldGridX = tempGridX;
            oldGridY = tempGridY;
        }

        /*for (int i = segments.size() - 1; i > 0; --i) {
            // move the segment to its new position in the grid

            segments[i].updateGridPosition(segments[i - 1].getGridX(), segments[i - 1].getGridY());
        }

        if (!segments.empty()) {
            //segments[0].updateGridPosition(oldGridX, oldGridY);
        }*/
    //}
}

void WormEntity::updateGridPosition(const int newGridX, const int newGridY) {
    grid->moveEntity(gridX, gridY, newGridX, newGridY);
    setGridPosition(newGridX, newGridY);
}

void WormEntity::handleCollision(Entity *other) {
}

/*void WormEntity::damage() {
    --lives;
}*/

bool WormEntity::checkForObstacle() const {
    if (hDirection == HDirection::LEFT) {
        return grid->isOccupied(gridX - 1, gridY);
    }
    return grid->isOccupied(gridX + 1, gridY);
}

/*void WormEntity::draw(RenderTarget &target, RenderStates states) const {
    for (const auto &segment: segments) {
        target.draw(segment, states);
    }
}*/
