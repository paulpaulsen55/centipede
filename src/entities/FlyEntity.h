#ifndef FLYENTITY_H
#define FLYENTITY_H
#include "Entity.h"
#include "../Grid.h"

/**
 * The `FlyEntity` class represents an entity that flies down the grid.
 * It is responsible for moving around the grid and handling collisions with other entities.
 */
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
