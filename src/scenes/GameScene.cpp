#include "GameScene.h"
#include "MenuScene.h"

// Grid: 32x24

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
        sceneManager.pushScene(std::make_unique<MenuScene>(800, 800));
    }
}

void GameScene::update(const float dt) {
    this->shootingDt += dt;

    // player movement collision with window bounds
    if (player.getPosition().left < 0) {
        player.setX(0);
    }
    if (player.getPosition().left > static_cast<float>(x) - player.getShape().getSize().x) {
        player.setX(static_cast<float>(x) - player.getShape().getSize().x);
    }

    // Shooting a projectile every 0.5 seconds maximum
    if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
        if (this->shootingDt > 0.5f) {
            projectileController.shootProjectile(
                player.getPosition().left + player.getShape().getSize().x / 2,
                player.getPosition().top);
            this->shootingDt = 0;
        }
    }

    player.update();
    projectileController.updateProjectiles();
}

void GameScene::draw(RenderTarget &target, const RenderStates states) const {
    target.draw(player);
    target.draw(projectileController);
}
