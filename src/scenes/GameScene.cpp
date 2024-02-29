#include "GameScene.h"
#include "MenuScene.h"
#include "../Constants.h"
#include "SFML/Window/Event.hpp"

GameScene::GameScene(): player(x / 2, y - 120) {
}

void GameScene::handleInput(Event event, RenderWindow &window) {
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
    if (Keyboard::isKeyPressed(Keyboard::Key::B)) {
        SceneManager::getInstance().changeScene(std::make_unique<MenuScene>());
    }
}

void GameScene::update(const float dt) {
    // check if a entity is hit by a projectile
    const auto projectiles = projectileController.getProjectiles();
    for (const auto &projectile: projectiles) {
        const int gridY = projectile.getPosition().top / (GRID_HEIGHT / GRID_ROWS) - 1;
        const int gridX = (GRID_COLS - 1) * (projectile.getPosition().left - 1) / x;
        if (grid.isOccupied(gridX, gridY)) {
            grid.damageEntity(gridX, gridY);
            projectileController.removeProjectile(projectile);
        }
    }

    this->shootingDt += dt;

    // player movement collision with window bounds
    if (player.getPosition().left < 0) {
        player.setX(0);
    }
    if (player.getPosition().left > static_cast<float>(x) - player.getShape().getSize().x) {
        player.setX(static_cast<float>(x) - player.getShape().getSize().x);
    }
    if (player.getPosition().top < 0) {
        player.setY(0);
    }
    if (player.getPosition().top > static_cast<float>(y) - 200 - player.getShape().getSize().y) {
        player.setY(static_cast<float>(y) - 200 - player.getShape().getSize().y);
    }

    // Shooting a projectile every PROJECTILE_COOLDOWN seconds maximum
    if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
        if (this->shootingDt > PROJECTILE_COOLDOWN) {
            projectileController.shootProjectile(player.getPosition().left, player.getPosition().top);
            this->shootingDt = 0;
        }
    }

    player.update();
    projectileController.updateProjectiles();
    grid.update(dt);
}

void GameScene::draw(RenderTarget &target, const RenderStates states) const {
    target.draw(grid);
    target.draw(player);
    target.draw(projectileController);
}
