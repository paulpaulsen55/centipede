#ifndef MUSHROOMENTITY_H
#define MUSHROOMENTITY_H
#include "Entity.h"
#include "SFML/Graphics/Text.hpp"


class MushroomEntity final : public Entity {
public:
    MushroomEntity();

    // The mushroom does not move
    void move(float dt) override {
    };

    // The mushroom does not move
    void updateGridPosition(int newGridX, int newGridY) override {
    };

    void handleCollision(Entity *other) override;

    void damage() override;
};


#endif //MUSHROOMENTITY_H
