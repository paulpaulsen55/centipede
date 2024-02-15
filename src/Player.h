#ifndef PLAYER_H
#define PLAYER_H
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"

using namespace sf;

class Player {
private:
    Vector2f position;

    RectangleShape playerShape;

    float playerSpeed = 1.5f;

public:
    Player(float startX, float startY);

    FloatRect getPosition();

    RectangleShape getShape();

    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    void update(unsigned int windowWidth, unsigned int windowHeight);
};



#endif //PLAYER_H
