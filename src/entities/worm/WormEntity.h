#ifndef WORMENTITY_H
#define WORMENTITY_H

#include "WormSegment.h"
#include "../Entity.h"
#include "../../Grid.h"

class WormSegment;

enum class HDirection { LEFT = -1, RIGHT = 1 };

enum class VDirection { UP, DOWN };

class WormEntity : public Entity {
public:
    explicit WormEntity(Grid *grid);

    void move(float dt) override;

    void updateGridPosition(int newGridX, int newGridY) override;

    void handleCollision(Entity *other) override;

    //void damage() override;

private:
    Grid *grid;

    HDirection hDirection = HDirection::RIGHT;
    VDirection vDirection = VDirection::DOWN;

    std::vector<WormSegment> segments;

    bool checkForObstacle() const;

    //void draw(RenderTarget &target, RenderStates states) const override;
};


#endif //WORMENTITY_H
