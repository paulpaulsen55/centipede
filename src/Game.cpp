#include "Game.h"

using namespace sf;

Game::Game(const int x, const int y):
    world(x, y),
    player(0, 0)
{

    window = new RenderWindow({800u, 600u}, "Centipede");
    window->setFramerateLimit(144);

    gameState.setState(GameState::State::MENU);
}

void Game::update(Time dt) {
    player.update();
}

void Game::render() const {
    this->window->clear(Color::Black);
    if (gameState == GameState::State::RUNNING) {
        this->window->draw(world);
    } else if (gameState == GameState::State::PAUSED) {
        // Draw pause screen
    } else if (gameState == GameState::State::MENU) {
        // Draw menu screen
    } else if (gameState == GameState::State::GAME_OVER) {
        // Draw game over screen
    }
    this->window->draw(player);
    this->window->display();
}

void Game::processEvent() {
    Event event{};
    while (window->pollEvent(event)) {
        if (event.type == Event::Closed) {
            window->close();
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        player.moveLeft();
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
        player.moveRight();
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
        player.moveUp();
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
        player.moveDown();
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
