#ifndef GRID_H
#define GRID_H
#include "entities/Entity.h"


/**
* This class represents a grid of entities in a sparse matrix.
*/
class Grid {
public:
    Grid(int width, int height);
    ~Grid();
    void placeEntity(int x, int y, Entity *e) const;
    Entity *getEntity(int x, int y) const;
    bool isOccupied(int x, int y) const;
    void removeEntity(int x, int y) const;


private:
    int width;
    int height;
    Entity ***grid;
};



#endif //GRID_H
