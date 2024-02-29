#include "WormSegment.h"

WormSegment::WormSegment(Grid *grid, const std::string &texture): Entity(texture), grid(grid) {
}

void WormSegment::updateGridPosition(int newGridX, int newGridY) {
    grid->moveEntity(gridX, gridY, newGridX, newGridY);
    setGridPosition(newGridX, newGridY);
}

void WormSegment::damage() {
    --lives;
}
