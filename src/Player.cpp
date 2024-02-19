#include "Player.h"

#include "SFML/Graphics/RenderTarget.hpp"

Player::Player(const float startX, const float startY) {
    position.x = startX;
    position.y = startY;

    playerShape.setSize(Vector2f(50, 20));
    playerShape.setPosition(position);
}

FloatRect Player::getPosition() const {
    return playerShape.getGlobalBounds();
}

void Player::setX(const float x) {
    position.x = x;
}

void Player::setY(const float y) {
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

void Player::draw(RenderTarget &target, RenderStates states) const {
    target.draw(playerShape, states);
}