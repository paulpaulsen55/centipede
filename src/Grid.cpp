#include "Grid.h"

Grid::Grid(const int width, const int height) : width(width), height(height) {
    grid = new Entity**[width];
    for(int i = 0; i < width; ++i) {
        grid[i] = new Entity*[height];
        for(int j = 0; j < height; ++j) {
            grid[i][j] = nullptr;
        }
    }
}

Grid::~Grid() {
    for(int i = 0; i < width; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

void Grid::placeEntity(const int x, const int y) const {
    if(x >= 0 && x < width && y >= 0 && y < height) {
        grid[x][y] = new Entity();
    }
}

Entity * Grid::getEntity(const int x, const int y) const {
    if(x >= 0 && x < width && y >= 0 && y < height) {
        return grid[x][y];
    }
    return nullptr;
}

bool Grid::isOccupied(const int x, const int y) const {
    return getEntity(x, y) != nullptr;
}
