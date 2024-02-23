#include "Projectile.h"

#include "Constants.h"

Projectile::Projectile(const float startX, const float startY): position(startX, startY), projectileSpeed(PROJECTILE_SPEED) {
    projectileShape.setSize(Vector2f(6, 10));
    projectileShape.setPosition(position);
}

FloatRect Projectile::getPosition() const {
    return projectileShape.getGlobalBounds();
}

RectangleShape Projectile::getShape() {
    return projectileShape;
}

void Projectile::update() {
    position.y -= projectileSpeed;
    projectileShape.setPosition(position);
}

bool Projectile::operator==(const Projectile &other) const {
    return position == other.position;
}
