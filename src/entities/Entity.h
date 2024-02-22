#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics/Sprite.hpp"

using namespace sf;

/**
 * The Entity class is an abstract class that represents an entity on the grid in the game.
 * It is responsible for handling the position and drawing of the entity.
 */
class Entity : public Drawable {
public:
    Entity(int x, int y, const Texture &texture, float speed);

    virtual void move() = 0;

    virtual void handleCollision(Entity *other) = 0;

protected:
    int x;
    int y;
    float speed;
    Sprite sprite;

private:
    void draw(RenderTarget &target, RenderStates states) const override;
};


#endif //ENTITY_H
