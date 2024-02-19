#include "MenuScene.h"
#include <memory>

#include "GameOverScene.h"
#include "SceneManager.h"
#include "SFML/Window/Mouse.hpp"

MenuScene::MenuScene(const int x, const int y) : x(x), y(y){
    font.loadFromFile("assets/BitPotion.ttf");

    title.setFont(font);
    title.setString("Centipede");
    title.setCharacterSize(100);
    title.setFillColor(Color::White);
    title.setPosition(200, 50);

    startButton.setSize(Vector2f(200, 100));
    startButton.setFillColor(Color::Green);
    startButton.setPosition(300, 300);

    startText.setFont(font);
    startText.setString("Start");
    startText.setCharacterSize(50);
    startText.setFillColor(Color::White);
    startText.setPosition(350, 320);

    exitButton.setSize(Vector2f(200, 100));
    exitButton.setFillColor(Color::Red);
    exitButton.setPosition(300, 500);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(50);
    exitText.setFillColor(Color::White);
    exitText.setPosition(350, 520);
}

void MenuScene::handleInput(RenderWindow &window, SceneManager &sceneManager) {
    if (Mouse::isButtonPressed(Mouse::Left)) {
        const Vector2i mousePosition = Mouse::getPosition(window);
        if (startButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            sceneManager.pushScene(std::make_unique<GameOverScene>(800,600));
        }
        if (exitButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            window.close();
        }
    }
}

void MenuScene::update(float dt) {
}

void MenuScene::draw(RenderTarget& target, RenderStates states) const {
    target.draw(title);

    target.draw(startButton);
    target.draw(startText);

    target.draw(exitButton);
    target.draw(exitText);
}
