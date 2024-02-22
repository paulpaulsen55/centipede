#ifndef FLYENTITY_H
#define FLYENTITY_H
#include "Entity.h"
#include "../TextureManager.h"


class FlyEntity : public Entity {
public:
    FlyEntity(int x, int y, TextureManager &textureManager);

    void move() override;

    void handleCollision(Entity *other) override;
};


#endif //FLYENTITY_H
