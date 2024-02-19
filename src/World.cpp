#include "World.h"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

using namespace sf;

World::World(int x, int y) : x(x), y(y) {
}

void World::draw(RenderTarget &target, RenderStates states) const {
    RectangleShape worldShape(Vector2f(200, 200));
    worldShape.setPosition(20, 20);
    target.draw(worldShape, states);
}

void World::update() {
}
