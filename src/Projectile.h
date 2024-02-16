#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"

using namespace sf;


class Projectile {

private:
    RectangleShape projectileShape;
    float projectileSpeed = 5.0f;

public:
    Vector2f position;

    Projectile(float startX, float startY);

    FloatRect getPosition();

    RectangleShape getShape();

    void update();
};



#endif //PROJECTILE_H
