#include "MenuScene.h"

#include <iostream>
#include <memory>
#include "GameScene.h"
#include "SceneManager.h"
#include "SFML/Window/Mouse.hpp"

MenuScene::MenuScene(const int x, const int y) : x(x), y(y) {
    font.loadFromFile("assets/BitPotion.ttf");

    title.setFont(font);
    title.setString("Centipede");
    title.setCharacterSize(100);
    title.setFillColor(Color::White);
    title.setPosition(x / 2 - (title.getGlobalBounds().width / 2), 50);

    startButton.setSize(Vector2f(200, 100));
    startButton.setFillColor(Color::Green);
    startButton.setPosition(x / 2 - 100, 300);

    startText.setFont(font);
    startText.setString("Start");
    startText.setCharacterSize(50);
    startText.setFillColor(Color::White);
    startText.setPosition(x / 2 - (startText.getGlobalBounds().width / 2), 320);

    exitButton.setSize(Vector2f(200, 100));
    exitButton.setFillColor(Color::Red);
    exitButton.setPosition(x / 2 - 100, 480);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(50);
    exitText.setFillColor(Color::White);
    exitText.setPosition(x / 2 - (exitText.getGlobalBounds().width / 2), 500);
}

void MenuScene::handleInput(const Event event, RenderWindow &window, SceneManager &sceneManager) {
    if (event.type == Event::MouseButtonReleased) {
        if (event.mouseButton.button == Mouse::Left) {
            const Vector2i mousePosition = Mouse::getPosition(window);
            if (startButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                sceneManager.pushScene(std::make_unique<GameScene>(800, 800));
            }
            if (exitButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                window.close();
            }
        }
    }
}

void MenuScene::update(float dt) {
    Scene::update(dt);
}

void MenuScene::draw(RenderTarget &target, RenderStates states) const {
    target.draw(title);

    target.draw(startButton);
    target.draw(startText);

    target.draw(exitButton);
    target.draw(exitText);
}
