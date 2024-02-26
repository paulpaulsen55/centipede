#ifndef MUSHROOMENTITY_H
#define MUSHROOMENTITY_H
#include "Entity.h"
#include "SFML/Graphics/Text.hpp"


class MushroomEntity : public Entity {
public:
    MushroomEntity(int x, int y);

    void move() override;

    void handleCollision(Entity *other) override;

    void damage() override;
};


#endif //MUSHROOMENTITY_H
