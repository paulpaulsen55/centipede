#ifndef WORMENTITY_H
#define WORMENTITY_H

#include <vector>

#include "WormSegment.h"
#include "../Entity.h"


class WormEntity : public Entity {
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
        return Vector2i(segments[0]->getGridX(), segments[0]->getGridY());
    }

    void damage() override;

    bool isAlive() const;


private:
    Grid *grid;

    std::vector<WormSegment *> segments;
};


#endif //WORMENTITY_H
