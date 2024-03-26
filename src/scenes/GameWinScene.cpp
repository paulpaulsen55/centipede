#include "GameWinScene.h"

#include "GameScene.h"
#include "MenuScene.h"
#include "SceneManager.h"
#include "../Constants.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"


GameWinScene::GameWinScene(const int score): score(score) {
    font.loadFromFile(FONT);

    menuButton.setSize(Vector2f(285, 75));
    menuButton.setFillColor(slate600);
    menuButton.setPosition(x / 2 - menuButton.getGlobalBounds().width / 2, 420);

    menuText.setFont(font);
    menuText.setString("Menu");
    menuText.setCharacterSize(50);
    menuText.setFillColor(Color::White);
    menuText.setPosition(x / 2 - (menuText.getGlobalBounds().width / 2), 422);

    scoreText.setFont(font);
    scoreText.setString(std::to_string(score));
    scoreText.setCharacterSize(64);
    scoreText.setFillColor(Color::Black);
    scoreText.setPosition(x / 2 - (scoreText.getGlobalBounds().width / 2), 160);

    texture.loadFromFile("assets/scenes/winbg.png");
    background.setTexture(texture);
}

void GameWinScene::handleInput(const Event event, RenderWindow &window) {
    const Vector2i mousePosition = Mouse::getPosition(window);

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
            if (menuButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                SceneManager::getInstance().changeScene(std::make_unique<MenuScene>());
            }
        }
    }
}

void GameWinScene::update(float dt) {
}

void GameWinScene::draw(RenderTarget &target, RenderStates states) const {
    target.draw(background);

    target.draw(menuButton);
    target.draw(menuText);

    target.draw(scoreText);
}
