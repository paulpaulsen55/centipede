#ifndef WORMSEGMENT_H
#define WORMSEGMENT_H

#include "../Entity.h"
#include "../../Grid.h"


class WormSegment : public Entity {
public:
    WormSegment(Grid *grid, const std::string &texture);

    void move(float dt) override {
    }

    void updateGridPosition(int newGridX, int newGridY) override;

    void handleCollision(Entity *other) override {
    }

    void damage() override;
private:
    Grid *grid;
};


#endif //WORMSEGMENT_H
