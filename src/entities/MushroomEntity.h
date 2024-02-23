#ifndef MUSHROOMENTITY_H
#define MUSHROOMENTITY_H
#include "Entity.h"
#include "SFML/Graphics/Text.hpp"


class MushroomEntity : public Entity {
public:
    MushroomEntity(int x, int y, const Texture &texture);

    void move() override;

    void handleCollision(Entity *other) override;
};


#endif //MUSHROOMENTITY_H
