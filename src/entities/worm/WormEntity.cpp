#include "WormEntity.h"

#include <memory>

#include "../MushroomEntity.h"
#include "../../Grid.h"


WormEntity::WormEntity(Grid *grid): Entity("assets/entities/wormhead.png"), grid(grid) {
    speed = 0.2f;
}

void WormEntity::initializeSegments() {
    segments.reserve(WORM_LENGTH);
    for (int i = 0; i < WORM_LENGTH; ++i) {
        std::string texture = "assets/entities/wormbody.png";
        if (i == 0) {
            texture = "assets/entities/wormhead.png";
        } else if (i == WORM_LENGTH - 1) {
            texture = "assets/entities/wormback.png";
        }
        auto segment = new WormSegment(grid, this, texture);
        segment->setGridPosition(WORM_LENGTH - 1 - i, 0);
        segments.push_back(segment);
        grid->placeEntity(WORM_LENGTH - 1 - i, 0, std::unique_ptr<WormSegment>(segment));
    }
}

void WormEntity::move(const float dt) {
    moveDt += dt;

    if (moveDt > speed) {
        moveDt = 0;

        Vector2i prevPos = segments[0]->getGridPosition();

        const Vector2i nextPos = segments[0]->getNextGridPosition();
        segments[0]->updateGridPosition(nextPos.x, nextPos.y);

        // make all the segments follow the head
        for (int i = 1; i < segments.size(); i++) {
            const Vector2i temp = segments[i]->getGridPosition();
            const Vector2i lastPos = segments[i - 1]->getGridPosition();
            if (temp.y != prevPos.y && prevPos.y == lastPos.y) {
                segments[i]->flipSprite();
            }
            segments[i]->updateGridPosition(prevPos.x, prevPos.y);
            prevPos = temp;
        }
    }
}


void WormEntity::handleCollision(Entity *other) {
    if (dynamic_cast<MushroomEntity *>(other) != nullptr || other == nullptr) {
        segments[0]->flipSprite();
        const Vector2i pos = segments[0]->getGridPosition();
        segments[0]->updateGridPosition(pos.x, pos.y + 1);
    }
}

void WormEntity::damage() {
    if (segments.size() <= 1) {
        return;
    }
    const Vector2i oldPos = segments[segments.size() - 1]->getGridPosition();
    grid->removeEntity(oldPos.x, oldPos.y);
    segments.pop_back();
    segments.back()->setSprite("assets/entities/wormback.png");
    grid->placeEntity(oldPos.y, oldPos.y, std::make_unique<MushroomEntity>());
}

bool WormEntity::isAlive() const {
    return segments.size() > 1;
}
