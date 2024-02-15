#include "Player.h"

Player::Player(float startX, float startY) {
    position.x = startX;
    position.y = startY;

    playerShape.setSize(Vector2f(50, 20));
    playerShape.setPosition(position);
}

FloatRect Player::getPosition() {
    return playerShape.getGlobalBounds();
}

RectangleShape Player::getShape() {
    return playerShape;
}

void Player::moveLeft() {
    position.x -= playerSpeed;
}

void Player::moveRight() {
    position.x += playerSpeed;
}

void Player::moveUp() {
    position.y -= playerSpeed;
}

void Player::moveDown() {
    position.y += playerSpeed;
}

void Player::update(const unsigned int windowWidth, const unsigned int windowHeight) {
    if (position.x < 0) {
        position.x = 0;
    }
    if (position.x > static_cast<float>(windowWidth) - playerShape.getSize().x) {
        position.x = static_cast<float>(windowWidth) - playerShape.getSize().x;
    }
    if (position.y < 0) {
        position.y = 0;
    }
    if (position.y > static_cast<float>(windowHeight) - playerShape.getSize().y) {
        position.y = static_cast<float>(windowHeight) - playerShape.getSize().y;
    }
    playerShape.setPosition(position);
}