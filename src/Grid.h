#ifndef GRID_H
#define GRID_H
#include "TextureManager.h"
#include "entities/Entity.h"


/**
* This class represents a grid of entities in a sparse matrix.
*/
class Grid final : public Drawable {
public:
    Grid(int width, int height);

    ~Grid() override;

    void update(float dt) const;

    void placeEntity(int gridX, int gridY, Entity *e) const;

    void removeEntity(int x, int y) const;

    Entity *getEntity(int gridX, int gridY) const;

    bool isOccupied(int x, int y) const;

private:
    int width;
    int height;
    Entity ***grid;
    TextureManager textureManager;


    void draw(RenderTarget &target, RenderStates states) const override;
};


#endif //GRID_H
