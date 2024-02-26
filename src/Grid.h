#ifndef GRID_H
#define GRID_H
#include "TextureManager.h"
#include "entities/Entity.h"


class Grid final : public Drawable {
public:
    Grid();

    ~Grid() override;

    void update(float dt) const;

    void placeEntity(int gridX, int gridY, Entity *e) const;

    void removeEntity(int x, int y) const;

    Entity *getEntity(int gridX, int gridY) const;

    void damageEntity(int gridX, int gridY) const;

    bool isOccupied(int gridX, int gridY) const;

private:
    int width;
    int height;
    Entity ***grid;

    void draw(RenderTarget &target, RenderStates states) const override;

    void generateMushrooms() const;
};


#endif //GRID_H
