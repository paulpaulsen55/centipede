/*#ifndef WORMENTITY_H
#define WORMENTITY_H
#include <vector>

#include "Entity.h"


class WormEntity : public Entity {
public:
    WormEntity();

    WormEntity(int x, int y, std::vector<Entity *> segments);

    void move(float dt) override;

    void handleCollision(Entity *other) override;

    void damage() override;

private:
    std::vector<Entity *> segments;
};


#endif //WORMENTITY_H*/
