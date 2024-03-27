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

    virtual void updateGridPosition(int newGridX, int newGridY) = 0;

    virtual Vector2i getNextGridPosition() const = 0;

    Vector2i getGridPosition() const;

    void update();

    bool isAlive() const;

    virtual void damage();

    void setGridPosition(int newGridX, int newGridY);

protected:
    float x = 0;
    float y = 0;
    int gridX = 0;
    int gridY = 0;
    Sprite sprite;

    float speed = 0.6f;
    int lives = 1;
    float moveDt = 0.0f;

private:
    void draw(RenderTarget &target, RenderStates states) const override;
};


#endif //ENTITY_H
