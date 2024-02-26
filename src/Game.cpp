#include "Game.h"

#include "scenes/MenuScene.h"

using namespace sf;

Game::Game() {
    window = new RenderWindow({800u, 800u}, "Centipede", Style::Titlebar | Style::Close);
    window->setFramerateLimit(144);

    sceneManager = &SceneManager::getInstance();
    sceneManager->pushScene(std::make_unique<MenuScene>());
}

void Game::update(const Time dt) const {
    sceneManager->getCurrentScene()->update(dt.asSeconds());
}

void Game::render() const {
    this->window->clear(Color::White);
    this->window->draw(*sceneManager->getCurrentScene());
    this->window->display();
}

void Game::processEvent() const {
    Event event{};
    while (window->pollEvent(event)) {
        if (event.type == Event::Closed) {
            window->close();
        }
    }
    sceneManager->getCurrentScene()->handleInput(event, *window);
}

void Game::run() {
    Time lastUpdateTime = Time::Zero;
    while (window->isOpen()) {
        this->processEvent();

        lastUpdateTime = clock.restart();
        while (lastUpdateTime > minFrameTime) {
            lastUpdateTime -= minFrameTime;
            this->update(minFrameTime);
        }
        this->update(lastUpdateTime);
        this->render();
    }
}

void Game::reset() {
}
