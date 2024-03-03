#ifndef GRID_H
#define GRID_H
#include <memory>

#include "Constants.h"
#include "TextureManager.h"
#include "entities/Entity.h"
#include "entities/SpawnTimer.h"
#include "entities/worm/WormEntity.h"

class WormEntity;

class Grid final : public Drawable {
public:
    Grid();

    void update(float dt);

    void placeEntity(int gridX, int gridY, std::unique_ptr<Entity> e);

    void moveEntity(int gridX, int gridY, int newGridX, int newGridY);

    void removeEntity(int x, int y);

    void damageEntity(int gridX, int gridY) const;

    bool isOccupied(int gridX, int gridY) const;

private:
    int width = GRID_COLS - 1;
    int height = GRID_ROWS - 1;
    std::vector<std::vector<std::unique_ptr<Entity> > > grid;

    SpawnTimer flyTimer{5};

    WormEntity worm;

    void draw(RenderTarget &target, RenderStates states) const override;

    void generateMushrooms();

    void spawnFly();

    void debugPrint() const;
};


#endif //GRID_H
