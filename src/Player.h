#ifndef PLAYER_H
#define PLAYER_H
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"

using namespace sf;


class Player final : public Drawable {
private:
    Vector2f position;
    RectangleShape playerShape;
    float playerSpeed = 2.5f;

    void draw(RenderTarget &target, RenderStates states) const override;

public:
    Player(float startX, float startY);

    FloatRect getPosition() const;

    RectangleShape getShape();

    void setX(float x);

    void setY(float y);

    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    void update();
};


#endif //PLAYER_H
