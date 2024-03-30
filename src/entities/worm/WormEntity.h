#ifndef WORMENTITY_H
#define WORMENTITY_H

#include <vector>

#include "WormSegment.h"
#include "../Entity.h"

/*
 * The `WormEntity` class represents an entity that moves horizontal until it hits something on the grid.
 * It is responsible for moving around the grid and handling collisions with other entities.
 * NOTE: The worm entity is made up of multiple segments that move together.
 */
class WormEntity final : public Entity {
public:
    explicit WormEntity(Grid *grid);

    void initializeSegments();

    void move(float dt) override;

    void updateGridPosition(int newGridX, int newGridY) override {
    };

    void handleCollision(Entity *other) override;

    Vector2i getNextGridPosition() const override {
        return segments[0]->getNextGridPosition();
    }

    Vector2i getHeadGridPosition() const {
        return segments[0]->getGridPosition();
    }

    void damage() override;

    bool isAlive() const override;

private:
    Grid *grid;

    std::vector<WormSegment *> segments;
};


#endif //WORMENTITY_H
