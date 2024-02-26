#ifndef GRID_H
#define GRID_H
#include "Constants.h"
#include "TextureManager.h"
#include "entities/Entity.h"
#include "entities/SpawnTimer.h"


class Grid final : public Drawable {
public:
    Grid();

    ~Grid() override;

    static Grid &getInstance();

    void update(float dt);

    void placeEntity(int gridX, int gridY, Entity *e) const;

    void moveEntity(Entity *e, int newGridX, int newGridY) const;

    void removeEntity(int x, int y) const;

    void damageEntity(int gridX, int gridY) const;

    bool isOccupied(int gridX, int gridY) const;

private:
    int width = GRID_COLS;
    int height = GRID_ROWS;
    Entity ***grid;

    SpawnTimer flyTimer{5};

    void draw(RenderTarget &target, RenderStates states) const override;

    void generateMushrooms() const;

    void spawnFly();
};


#endif //GRID_H
