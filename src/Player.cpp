#include "Player.h"

#include "Constants.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"

Player::Player(const float startX, const float startY): playerSpeed(PLAYER_SPEED) {
    position.x = startX;
    position.y = startY;
}

FloatRect Player::getPosition() const {
    return sprite.getGlobalBounds();
}

void Player::setX(const float x) {
    position.x = x;
}

void Player::setY(const float y) {
    position.y = y;
}

FloatRect Player::getShape() const {
    return sprite.getLocalBounds();

}

void Player::setTexture(const Texture &texture) {
    this->sprite.setTexture(texture);
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
    sprite.setPosition(position);
}

void Player::draw(RenderTarget &target, RenderStates states) const {
    target.draw(sprite, states);
}
