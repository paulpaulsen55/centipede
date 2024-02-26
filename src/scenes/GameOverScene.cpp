#include "GameOverScene.h"
#include <memory>
#include "MenuScene.h"
#include "SceneManager.h"
#include "../Constants.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"

GameOverScene::GameOverScene() {
    font.loadFromFile(FONT);

    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(100);
    gameOverText.setPosition(200, 50);

    restartButton.setSize(Vector2f(200, 100));
    restartButton.setFillColor(Color::Green);
    restartButton.setPosition(300, 300);

    restartText.setFont(font);
    restartText.setString("Restart");
    restartText.setCharacterSize(50);
    restartText.setFillColor(Color::White);
    restartText.setPosition(350, 320);
}

void GameOverScene::handleInput(const Event event, RenderWindow &window) {
    if (event.type == Event::MouseButtonReleased) {
        if (event.mouseButton.button == Mouse::Left) {
            if (const Vector2i mousePosition = Mouse::getPosition(window); restartButton.getGlobalBounds().contains(
                mousePosition.x, mousePosition.y)) {
                SceneManager::getInstance().changeScene(std::make_unique<MenuScene>());
            }
        }
    }
}

void GameOverScene::update(float dt) {
}

void GameOverScene::draw(RenderTarget &target, RenderStates states) const {
    target.draw(gameOverText);

    target.draw(restartButton);
    target.draw(restartText);
}
