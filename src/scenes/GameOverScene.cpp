#include "GameOverScene.h"
#include <memory>

#include "GameScene.h"
#include "MenuScene.h"
#include "SceneManager.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"

GameOverScene::GameOverScene() {
    font.loadFromFile(FONT);

    restartButton.setSize(Vector2f(285, 75));
    restartButton.setFillColor(slate800);
    restartButton.setPosition(x / 2 - restartButton.getGlobalBounds().width / 2, 400);

    restartText.setFont(font);
    restartText.setString("Neustarten");
    restartText.setCharacterSize(50);
    restartText.setFillColor(Color::White);
    restartText.setPosition(x / 2 - (restartText.getGlobalBounds().width / 2), 402);

    menuButton.setSize(Vector2f(285, 75));
    menuButton.setFillColor(slate600);
    menuButton.setPosition(x / 2 - menuButton.getGlobalBounds().width / 2, 520);

    menuText.setFont(font);
    menuText.setString("Menu");
    menuText.setCharacterSize(50);
    menuText.setFillColor(Color::White);
    menuText.setPosition(x / 2 - (menuText.getGlobalBounds().width / 2), 522);

    texture.loadFromFile("assets/scenes/losebg.png");
    background.setTexture(texture);
}

void GameOverScene::handleInput(const Event event, RenderWindow &window) {
    const Vector2i mousePosition = Mouse::getPosition(window);

    // Check if mouse is over the restartButton
    if (restartButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        const Color originalColor = restartButton.getFillColor();
        const Color newColor(originalColor.r, originalColor.g, originalColor.b, 180);
        restartButton.setFillColor(newColor);
    } else {
        restartButton.setFillColor(slate800);
    }

    // Check if mouse is over the menuButton
    if (menuButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        const Color originalColor = menuButton.getFillColor();
        const Color newColor(originalColor.r, originalColor.g, originalColor.b, 180);
        menuButton.setFillColor(newColor);
    } else {
        menuButton.setFillColor(slate600);
    }

    if (event.type == Event::MouseButtonReleased) {
        if (event.mouseButton.button == Mouse::Left) {
            if (restartButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                SceneManager::getInstance().changeScene(std::make_unique<GameScene>());
            }
            if (menuButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                SceneManager::getInstance().changeScene(std::make_unique<MenuScene>());
            }
        }
    }
}

void GameOverScene::update(float dt) {
}

void GameOverScene::draw(RenderTarget &target, RenderStates states) const {
    target.draw(background);

    target.draw(menuButton);
    target.draw(menuText);

    target.draw(restartButton);
    target.draw(restartText);
}
