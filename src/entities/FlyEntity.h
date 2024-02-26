#ifndef FLYENTITY_H
#define FLYENTITY_H
#include "Entity.h"


class FlyEntity final : public Entity {
public:
    FlyEntity();

    void move(float dt) override;

    void handleCollision(Entity *other) override;
};


#endif //FLYENTITY_H
