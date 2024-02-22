#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"

using namespace sf;


class Projectile {
public:
    Vector2f position;

    Projectile(float startX, float startY);

    FloatRect getPosition() const;

    RectangleShape getShape();

    void update();

private:
    RectangleShape projectileShape;
    float projectileSpeed = 5.0f;
};



#endif //PROJECTILE_H
