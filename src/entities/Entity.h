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
    explicit Entity(const std::string &texture);

    virtual void move(float dt) = 0;

    virtual void handleCollision(Entity *other) = 0;

    void setPosition(int x, int y);

    void setGridPosition(int gridX, int gridY);

    bool isAlive() const;

    virtual void damage();

    int getGridX() const;

    int getGridY() const;

protected:
    int x = 0;
    int y = 0;
    int gridX = 0;
    int gridY = 0;
    float speed = 0.4f;
    int lives = 1;
    float moveDt = 0.0f;
    Sprite sprite;

private:
    void draw(RenderTarget &target, RenderStates states) const override;
};


#endif //ENTITY_H
