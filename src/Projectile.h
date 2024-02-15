#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"

using namespace sf;


class Projectile {
    Vector2f position;
    RectangleShape projectileShape;
    float projectileSpeed = 1.5f;


    Projectile();
};



#endif //PROJECTILE_H
