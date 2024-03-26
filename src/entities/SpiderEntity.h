#ifndef SPIDERENTITY_H
#define SPIDERENTITY_H
#include "Entity.h"


class Grid;

class SpiderEntity final : public Entity {
public:
    SpiderEntity(int startingGridX, Grid *grid);

    void move(float dt) override;

    void handleCollision(Entity *other) override;

    void updateGridPosition(int newGridX, int newGridY) override;

    Vector2i getNextGridPosition() const override;
private:
    Grid *grid;

    int startingGridX;
};



#endif //SPIDERENTITY_H
