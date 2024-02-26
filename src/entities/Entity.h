#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "SFML/Graphics/Sprite.hpp"

using namespace sf;

/**
 * The Entity class is an abstract class that represents an entity on the grid in the game.
 * It is responsible for handling the position and drawing of the entity.
 */
class Entity : public Drawable {
public:
    Entity(int x, int y, const std::string &texture, float speed);

    virtual void move() = 0;

    virtual void handleCollision(Entity *other) = 0;

    void setPosition(int x, int y);

    bool isAlive() const;

    void damage();

protected:
    int x;
    int y;
    float speed;
    Sprite sprite;
    int lives = 1;

private:
    void draw(RenderTarget &target, RenderStates states) const override;
};


#endif //ENTITY_H
