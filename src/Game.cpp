#include "Game.h"

using namespace sf;

void Game::initWindow() {
    window = new RenderWindow({800u, 600u}, "Centipede");
    window->setFramerateLimit(144);
}

void Game::initKeys() {
}

void Game::initPlayer() {
}

void Game::initLevel() {
}

Game::Game(int x, int y) {
}

void Game::update(Time dt) {
}

void Game::render() {
}

void Game::processEvent() {
    Event event{};
    while (window->pollEvent(event)) {
        if (event.type == Event::Closed) {
            window->close();
        } else if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::Key::Escape) {
                window->close();
            }
        }
    }
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
