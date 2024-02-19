#include "Game.h"

#include "scenes/MenuScene.h"

using namespace sf;

Game::Game(const int x, const int y):
    player(x / 2,  y - 20)
{

    window = new RenderWindow({800u, 600u}, "Centipede");
    window->setFramerateLimit(144);

    sceneManager.pushScene(std::make_unique<MenuScene>());

    gameState.setState(GameState::State::MENU);
}

void Game::update(Time dt) {
    if (player.getPosition().left < 0) {
        player.setX(0);
    }
    if (player.getPosition().left > window->getSize().x - player.getShape().getSize().x) {
        player.setX(window->getSize().x  - player.getShape().getSize().x);
    }
    player.update();
}

void Game::render() const {
    this->window->clear(Color::Black);

    this->window->draw(*sceneManager.getCurrentScene());
    this->window->draw(player);
    this->window->display();
}

void Game::processEvent() const {
    Event event{};
    while (window->pollEvent(event)) {
        if (event.type == Event::Closed) {
            window->close();
        }
    }
    sceneManager.getCurrentScene()->handleInput(*window);
    /*if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        player.moveLeft();
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
        player.moveRight();
    }*/
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
