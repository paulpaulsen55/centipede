#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"

using namespace sf;

/**
 * The Projectile class represents one projectile that the player can shoot.
 * It provides methods for updating the projectile and ensuring that it moves in the correct direction.
 */
class Projectile {
public:
    Vector2f position;

    Projectile(float startX, float startY);

    FloatRect getPosition() const;

    RectangleShape getShape();

    void update();

    bool operator==(const Projectile &other) const;

private:
    RectangleShape projectileShape;
    float projectileSpeed;
};


#endif //PROJECTILE_H
