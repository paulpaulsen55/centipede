#include "MenuScene.h"

#include <memory>
#include "GameScene.h"
#include "GameWinScene.h"
#include "SceneManager.h"
#include "../Constants.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"

MenuScene::MenuScene() {
    font.loadFromFile(FONT);

    startButton.setSize(Vector2f(285, 75));
    startButton.setFillColor(slate800);
    startButton.setPosition(x / 2 - startButton.getGlobalBounds().width / 2, 380);

    startText.setFont(font);
    startText.setString("Starten");
    startText.setCharacterSize(50);
    startText.setFillColor(Color::White);
    startText.setPosition(x / 2 - (startText.getGlobalBounds().width / 2), 382);

    exitButton.setSize(Vector2f(285, 75));
    exitButton.setFillColor(slate600);
    exitButton.setPosition(x / 2 - exitButton.getGlobalBounds().width / 2, 500);

    exitText.setFont(font);
    exitText.setString("Beenden");
    exitText.setCharacterSize(50);
    exitText.setFillColor(Color::White);
    exitText.setPosition(x / 2 - (exitText.getGlobalBounds().width / 2), 502);

    texture.loadFromFile("assets/scenes/menubg.png");
    background.setTexture(texture);
}

void MenuScene::handleInput(const Event event, RenderWindow &window) {
    const Vector2i mousePosition = Mouse::getPosition(window);

    // Check if mouse is over the startButton
    if (startButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        const Color originalColor = startButton.getFillColor();
        const Color newColor(originalColor.r, originalColor.g, originalColor.b, 180);
        startButton.setFillColor(newColor);
    } else {
        startButton.setFillColor(slate800);
    }

    // Check if mouse is over the exitButton
    if (exitButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        const Color originalColor = exitButton.getFillColor();
        const Color newColor(originalColor.r, originalColor.g, originalColor.b, 180);
        exitButton.setFillColor(newColor);
    } else {
        exitButton.setFillColor(slate600);
    }

    if (event.type == Event::MouseButtonReleased) {
        if (event.mouseButton.button == Mouse::Left) {

            if (startButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                SceneManager::getInstance().changeScene(std::make_unique<GameScene>());
            }
            if (exitButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                window.close();
            }
        }
    }
}

void MenuScene::update(float dt) {
}

void MenuScene::draw(RenderTarget &target, RenderStates states) const {
    target.draw(background);

    target.draw(startButton);
    target.draw(startText);

    target.draw(exitButton);
    target.draw(exitText);
}
