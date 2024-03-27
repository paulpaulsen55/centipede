#ifndef FLYENTITY_H
#define FLYENTITY_H
#include "Entity.h"
#include "../Grid.h"


class FlyEntity final : public Entity {
public:
    explicit FlyEntity(Grid *grid);

    void move(float dt) override;

    void handleCollision(Entity *other) override;

    void updateGridPosition(int newGridX, int newGridY) override;

    Vector2i getNextGridPosition() const override;

private:
    Grid *grid;
};


#endif //FLYENTITY_H
