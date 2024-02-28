#include "Grid.h"

#include <random>

#include "Constants.h"
#include "UtilityFunctions.h"
#include "entities/FlyEntity.h"
#include "entities/MushroomEntity.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

Grid::Grid() {
    for (int i = 0; i < width; ++i) {
        std::vector<std::unique_ptr<Entity> > row;
        for (int j = 0; j < height; ++j) {
            row.push_back(nullptr);
        }
        grid.push_back(std::move(row));
    }
    //generateMushrooms();
    placeEntity(0, 0, std::make_unique<FlyEntity>());
    printf("C%d 0\n", grid[0][0] == nullptr);
}

Grid &Grid::getInstance() {
    static Grid instance;
    return instance;
}

void Grid::placeEntity(const int gridX, const int gridY, std::unique_ptr<Entity> e) {
    if (gridX >= 0 && gridX < width && gridY >= 0 && gridY < height && grid[gridX][gridY] == nullptr) {
        grid[gridX][gridY] = std::move(e);
        grid[gridX][gridY]->setPosition(gridX, gridY);
    }
}

void Grid::moveEntity(const int gridX, const int gridY, const int newGridX, const int newGridY) {
    if (gridX >= 0 && gridX < width && gridY >= 0 && gridY < height &&
        newGridX >= 0 && newGridX < width && newGridY >= 0 && newGridY < height) {
        printf("M%d %d %d %d %d %d\n", gridX, gridY, newGridX, newGridY, grid[gridX][gridY] == nullptr, grid[newGridX][newGridY] == nullptr);
        if (grid[gridX][gridY] != nullptr) {
            debugPrint();
            // Transfer ownership to the new grid cell
            grid[newGridX][newGridY] = std::move(grid[gridX][gridY]);
            grid[newGridX][newGridY]->setPosition(newGridX, newGridY);
            // Reset the old grid cell
            grid[gridX][gridY] = nullptr;
            debugPrint();
        }
    }
}

bool Grid::isOccupied(const int gridX, const int gridY) const {
    if (gridX < 0 || gridX >= width || gridY < 0 || gridY >= height) {
        return true;
    }
    return grid[gridX][gridY] != nullptr;
}

void Grid::removeEntity(const int x, const int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
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

void Grid::generateMushrooms() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height - 3; ++j) {
            if (generateRandomNumber(0, 100) <= MUSHROOM_SPAWNCHANCE)
                placeEntity(i, j, std::make_unique<MushroomEntity>());
        }
    }
}

void Grid::spawnFly() {
    int x;
    do {
        x = generateRandomNumber(0, width - 1);
    } while (isOccupied(x, 0));
    placeEntity(x, 0, std::make_unique<FlyEntity>());
    flyTimer.reset();
}

void Grid::debugPrint() const {
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < width; ++i) {
            if (grid[i][j] == nullptr) {
                printf("n");
            } else {
                printf("E");
            }
        }
        printf("\n");
    }
    printf("\n");
}