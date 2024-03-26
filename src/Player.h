#ifndef PLAYER_H
#define PLAYER_H
#include "Constants.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"

using namespace sf;


class Player final : public Drawable {
public:
    Player(float startX, float startY);

    FloatRect getPosition() const;

    FloatRect getShape() const;

    void setX(float x);

    void setY(float y);

    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    void update();

private:
    Vector2f position;
    Sprite sprite;
    float playerSpeed = PLAYER_SPEED;

    void draw(RenderTarget &target, RenderStates states) const override;
};


#endif //PLAYER_H
