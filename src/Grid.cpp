#include "Grid.h"

#include <random>

#include "Constants.h"
#include "entities/FlyEntity.h"
#include "entities/MushroomEntity.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

Grid::Grid(TextureManager *textureManager): width(GRID_COLS), height(GRID_ROWS), textureManager(textureManager) {
    grid = new Entity **[width];
    for (int i = 0; i < width; ++i) {
        grid[i] = new Entity *[height];
        for (int j = 0; j < height; ++j) {
            grid[i][j] = nullptr;
        }
    }

    textureManager->loadTexture("fly", "assets/fly.png");
    textureManager->loadTexture("mushroom", "assets/mushroom.png");

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

/**
 * Places an entity on the grid at the given points.
 * @param gridX The x position of the entity in the grid, e.g. 10.
 * @param gridY The y position of the entity in the grid, e.g. 10.
 * @param e The entity to place.
 */
void Grid::placeEntity(const int gridX, const int gridY, Entity *e) const {
    if (gridX >= 0 && gridX < width && gridY >= 0 && gridY < height) {
        grid[gridX][gridY] = e;
        e->setPosition(gridX * 800 / width + 1, gridY * 600 / height + 1);
    }
}

Entity *Grid::getEntity(const int gridX, const int gridY) const {
    if (gridX >= 0 && gridX < width && gridY >= 0 && gridY < height) {
        return grid[gridX][gridY];
    }
    return nullptr;
}

bool Grid::isOccupied(const int gridX, const int gridY) const {
    return getEntity(gridX, gridY) != nullptr;
}

void Grid::removeEntity(const int x, const int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        delete grid[x][y];
        grid[x][y] = nullptr;
    }
}

void Grid::update(float dt) const {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->move();
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
}

void Grid::damageEntity(const int gridX, const int gridY) const {
    printf("damaging entity at %d, %d\n", gridX, gridY);
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
        sf::RectangleShape line(sf::Vector2f(1, target.getSize().y));
        line.setPosition(i * cellWidth, 0);
        line.setFillColor(sf::Color::Black);
        target.draw(line, states);
    }

    for (int i = 0; i <= height; ++i) {
        sf::RectangleShape line(sf::Vector2f(target.getSize().x, 1));
        line.setPosition(0, i * cellHeight);
        line.setFillColor(sf::Color::Black);
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
            std::random_device rd;
            std::mt19937 gen(rd());
            if (std::uniform_int_distribution<int> dist(1, 100); dist(gen) <= MUSHROOM_SPAWNCHANCE)
                placeEntity(i, j, new MushroomEntity(i, j, textureManager->getTexture("mushroom")));
        }
    }
}
