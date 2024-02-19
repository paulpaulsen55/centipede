#include "GameScene.h"

#include "MenuScene.h"

GameScene::GameScene(const int x, const int y):
    x(x),
    y(y),
    player(x / 2, y - 20) {
}

void GameScene::handleInput(Event event, RenderWindow &window, SceneManager &sceneManager) {
    if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        player.moveLeft();
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
        player.moveRight();
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::P)) {
        sceneManager.pushScene(std::make_unique<MenuScene>(800, 600));
    }
}

void GameScene::update(const float dt) {
    if (player.getPosition().left < 0) {
        player.setX(0);
    }
    if (player.getPosition().left > static_cast<float>(x) - player.getShape().getSize().x) {
        player.setX(static_cast<float>(x) - player.getShape().getSize().x);
    }
    player.update();
}

void GameScene::draw(RenderTarget &target, const RenderStates states) const {
    target.draw(player);
}
