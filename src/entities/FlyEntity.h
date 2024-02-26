#ifndef FLYENTITY_H
#define FLYENTITY_H
#include "Entity.h"


class FlyEntity : public Entity {
public:
    FlyEntity(int x, int y);

    void move() override;

    void handleCollision(Entity *other) override;
};


#endif //FLYENTITY_H
