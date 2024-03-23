#include "Grid.h"

#include "Constants.h"
#include "UtilityFunctions.h"
#include "entities/FlyEntity.h"
#include "entities/MushroomEntity.h"
#include "entities/worm/WormEntity.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

Grid::Grid(): worm(this) {
    for (int i = 0; i < width; ++i) {
        std::vector<std::unique_ptr<Entity> > row;
        for (int j = 0; j < height; ++j) {
            row.push_back(nullptr);
        }
        grid.push_back(std::move(row));
    }
    generateMushrooms();
    worm.initializeSegments();
}

void Grid::placeEntity(const int gridX, const int gridY, std::unique_ptr<Entity> e) {
    if (gridX >= 0 && gridX <= width && gridY >= 0 && gridY < height && grid[gridX][gridY] == nullptr) {
        grid[gridX][gridY] = std::move(e);
        grid[gridX][gridY]->setGridPosition(gridX, gridY);
    }
}

void Grid::moveEntity(const int gridX, const int gridY, const int newGridX, const int newGridY) {
    if (newGridX >= 0 && newGridX <= width && newGridY >= 0 && newGridY <= height) {
        if (grid[gridX][gridY] != nullptr) {
            grid[newGridX][newGridY] = std::move(grid[gridX][gridY]);
            grid[newGridX][newGridY]->setGridPosition(newGridX, newGridY);
            grid[gridX][gridY] = nullptr;
        }
    }
}

bool Grid::isOccupied(const int gridX, const int gridY) const {
    if (gridX < 0 || gridX >= width || gridY < 0 || gridY >= height) {
        return true;
    }
    return grid[gridX][gridY] != nullptr;
}

bool Grid::isOccupiedByWorm(const int gridX, const int gridY) const {
    if (gridX < 0 || gridX >= width || gridY < 0 || gridY >= height || grid[gridX][gridY] == nullptr) {
        return false;
    }
    return dynamic_cast<WormSegment *>(grid[gridX][gridY].get()) != nullptr;
}

void Grid::removeEntity(const int x, const int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[x][y] = nullptr;
    }
}

void Grid::update(const float dt) {
    // update the spawn timers
    flyTimer.update(dt);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (grid[i][j] != nullptr) {
                if (!grid[i][j]->isAlive()) {
                    removeEntity(i, j);
                    continue;
                }

                if (const Vector2i nextPos = grid[i][j]->getNextGridPosition(); isOccupied(nextPos.x, nextPos.y)) {
                    const bool offScreen = nextPos.x < 0 || nextPos.x >= width;
                    if (const Vector2i h = worm.getHeadGridPosition(); h.x == i && h.y == j) {
                        worm.handleCollision(offScreen ? nullptr : grid[nextPos.x][nextPos.y].get());
                    } else {
                        grid[i][j]->handleCollision(offScreen ? nullptr : grid[nextPos.x][nextPos.y].get());
                    }
                } else {
                    grid[i][j]->move(dt);
                }
            }
        }
    }

    worm.move(dt);

    if (flyTimer.shouldSpawn()) {
        spawnFly();
        flyTimer.reset();
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
    /*for (int i = 0; i <= width; ++i) {
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
    }*/

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (grid[i][j] != nullptr) {
                target.draw(*grid[i][j]);
            }
        }
    }
}

void Grid::generateMushrooms() {
    for (int i = 2; i < width - 2; ++i) {
        for (int j = 1; j < height - 3; ++j) {
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
    placeEntity(x, 0, std::make_unique<FlyEntity>(this));
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
