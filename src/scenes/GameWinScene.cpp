#include "GameWinScene.h"

#include "MenuScene.h"
#include "SceneManager.h"
#include "../Constants.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"


GameWinScene::GameWinScene() {
    font.loadFromFile(FONT);

    winText.setFont(font);
    winText.setString("WINNER");
    winText.setCharacterSize(100);
    winText.setPosition(200, 50);
    winText.setFillColor(slate800);

    menuButton.setSize(Vector2f(200, 100));
    menuButton.setFillColor(Color::Green);
    menuButton.setPosition(300, 300);

    menuText.setFont(font);
    menuText.setString("Restart");
    menuText.setCharacterSize(50);
    menuText.setFillColor(Color::Black);
    menuText.setPosition(350, 320);
}

void GameWinScene::handleInput(const Event event, RenderWindow &window) {
    if (event.type == Event::MouseButtonReleased) {
        if (event.mouseButton.button == Mouse::Left) {
            if (const Vector2i mousePosition = Mouse::getPosition(window); menuButton.getGlobalBounds().contains(
                mousePosition.x, mousePosition.y)) {
                SceneManager::getInstance().changeScene(std::make_unique<MenuScene>());
            }
        }
    }
}

void GameWinScene::update(float dt) {
}

void GameWinScene::draw(RenderTarget &target, RenderStates states) const {
    target.draw(winText);

    target.draw(menuButton);
    target.draw(menuText);
}
