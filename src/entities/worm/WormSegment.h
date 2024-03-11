#ifndef WORMSEGMENT_H
#define WORMSEGMENT_H

#include "../Entity.h"

class Grid;

class WormEntity;

enum class HDirection { LEFT = -1, RIGHT = 1 };




class WormSegment : public Entity {
public:
    WormSegment(Grid *grid, WormEntity *wormEntity, const std::string &texture);

    void move(float dt) override {
    }

    void handleCollision(Entity *other) override {
    }

    void updateGridPosition(int newGridX, int newGridY) override;

    Vector2i getNextGridPosition() const override;

    void flipSprite();

    void setSprite(const std::string &texture);

    HDirection getHDirection() const {
        return hDirection;
    }


private:
    Grid *grid;
    WormEntity *wormEntity;
    HDirection hDirection = HDirection::RIGHT;
};
#endif //WORMSEGMENT_H
