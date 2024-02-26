#include "Grid.h"

#include <random>

#include "Constants.h"
#include "UtilityFunctions.h"
#include "entities/FlyEntity.h"
#include "entities/MushroomEntity.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

Grid::Grid() {
    grid = new Entity **[width];
    for (int i = 0; i < width; ++i) {
        grid[i] = new Entity *[height];
        for (int j = 0; j < height; ++j) {
            grid[i][j] = nullptr;
        }
    }

    this->generateMushrooms();
}

Grid::~Grid() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            delete grid[i][j];
        }
        delete[] grid[i];
    }
    delete[] grid;
}

Grid &Grid::getInstance() {
    static Grid instance;
    return instance;
}

/**
 * Places an entity on the grid at the given points.
 * @param gridX The x position of the entity in the grid, e.g. 10.
 * @param gridY The y position of the entity in the grid, e.g. 10.
 * @param e The entity to place.
 */
void Grid::placeEntity(const int gridX, const int gridY, Entity *e) const {
    if (gridX >= 0 && gridX < width && gridY >= 0 && gridY < height && grid[gridX][gridY] == nullptr) {
        printf("Placing entity at %d %d\n", gridX, gridY);
        grid[gridX][gridY] = e;
        e->setGridPosition(gridX, gridY);
        e->setPosition(gridX * GRID_WIDTH / width + 1, gridY * GRID_HEIGHT / height + 1);
    }
}

void Grid::moveEntity(Entity *e, const int newGridX, const int newGridY) const {
    if (newGridX >= 0 && newGridX < width && newGridY >= 0 && newGridY < height) {
        grid[e->getGridX()][e->getGridY()] = nullptr;
        grid[newGridX][newGridY] = e;
        e->setGridPosition(newGridX, newGridY);
        e->setPosition(newGridX * GRID_WIDTH / width + 1, newGridY * GRID_HEIGHT / height + 1);
    }
}

bool Grid::isOccupied(const int gridX, const int gridY) const {
    if (gridX < 0 || gridX >= width || gridY < 0 || gridY >= height) {
        return true;
    }
    return grid[gridX][gridY] != nullptr;
}

void Grid::removeEntity(const int x, const int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        delete grid[x][y];
        grid[x][y] = nullptr;
    }
}

void Grid::update(const float dt) {
    // update the spawn timers
    flyTimer.update(dt);

    // move all entities
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->move(dt);
            }
        }
    }
    // if a entity has no more lives, remove it from the grid
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (grid[i][j] != nullptr && !grid[i][j]->isAlive()) {
                removeEntity(i, j);
            }
        }
    }

    if (flyTimer.shouldSpawn()) {
        spawnFly();
    }
}

void Grid::damageEntity(const int gridX, const int gridY) const {
    if (gridX >= 0 && gridX < width && gridY >= 0 && gridY < height) {
        if (grid[gridX][gridY] != nullptr) {
            grid[gridX][gridY]->damage();
        }
    }
}

void Grid::draw(RenderTarget &target, RenderStates states) const {
    float cellWidth = 800 / static_cast<float>(width);
    float cellHeight = 600 / static_cast<float>(height);

    // Draw grid lines
    for (int i = 0; i <= width; ++i) {
        RectangleShape line(Vector2f(1, target.getSize().y));
        line.setPosition(i * cellWidth, 0);
        line.setFillColor(Color::Black);
        target.draw(line, states);
    }

    for (int i = 0; i <= height; ++i) {
        RectangleShape line(Vector2f(target.getSize().x, 1));
        line.setPosition(0, i * cellHeight);
        line.setFillColor(Color::Black);
        target.draw(line, states);
    }

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (grid[i][j] != nullptr) {
                target.draw(*grid[i][j]);
            }
        }
    }
}

void Grid::generateMushrooms() const {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height - 3; ++j) {
            if (generateRandomNumber(0, 100) <= MUSHROOM_SPAWNCHANCE)
                placeEntity(i, j, new MushroomEntity());
        }
    }
}

void Grid::spawnFly() {
    int x;
    do {
        x = generateRandomNumber(0, width - 1);
    } while (isOccupied(x, 0));
    placeEntity(x, 0, new FlyEntity());
    flyTimer.reset();
}
