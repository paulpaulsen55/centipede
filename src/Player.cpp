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

void Player::setX(float x) {
    position.x = x;
}

void Player::setY(float y) {
    position.y = y;
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

void Player::update() {
    playerShape.setPosition(position);
}