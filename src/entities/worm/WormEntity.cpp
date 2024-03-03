#include "WormEntity.h"

#include <memory>

#include "../FlyEntity.h"
#include "../MushroomEntity.h"
#include "../../Grid.h"


WormEntity::WormEntity(Grid *grid): Entity("assets/wormhead.png"), grid(grid) {
}

void WormEntity::initializeSegments() {
    segments.reserve(WORM_LENGTH);
    for (int i = 0; i < WORM_LENGTH; ++i) {
        std::string texture = "assets/wormbody.png";
        if (i == 0) {
            texture = "assets/wormhead.png";
        } else if (i == WORM_LENGTH - 1) {
            texture = "assets/wormback.png";
        }
        auto segment = new WormSegment(grid, this, texture);
        segment->setGridPosition(6 - 1 - i, 0);
        segments.push_back(segment);
        grid->placeEntity(6 - 1 - i, 0, std::unique_ptr<WormSegment>(segment));
    }
}

void WormEntity::move(const float dt) {
    this->moveDt += dt;

    if (moveDt > speed) {
        moveDt = 0;

        Vector2i prevPos = segments[0]->getGridPosition();

        const Vector2i nextPos = segments[0]->getNextGridPosition();
        segments[0]->updateGridPosition(nextPos.x, nextPos.y);

        for (int i = 1; i < segments.size(); i++) {
            const Vector2i temp = segments[i]->getGridPosition();

            if (temp.y != prevPos.y && prevPos.y == segments[i-1]->getGridY()) {
                segments[i]->flipSprite();
            }
            segments[i]->updateGridPosition(prevPos.x, prevPos.y);
            prevPos = temp;
        }
    }
}

void WormEntity::handleCollision(Entity *other) {
    if (other == nullptr || dynamic_cast<MushroomEntity *>(other) != nullptr) {
        segments[0]->flipSprite();
        segments[0]->updateGridPosition(segments[0]->getGridX(), segments[0]->getGridY() + 1);
        printf("WormSegment collision\n");
    } else if (dynamic_cast<FlyEntity *>(other) != nullptr) {
        printf("Fly collision\n");
    }
}
