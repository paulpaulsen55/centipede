#include "GameScene.h"
#include "MenuScene.h"
#include "../Constants.h"
#include "SFML/Window/Event.hpp"

GameScene::GameScene(const int x, const int y): x(x), y(y),
                                                player(x / 2, y - 120) {
}

void GameScene::handleInput(Event event, RenderWindow &window, SceneManager &sceneManager) {
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

    // check if a entity is hit by a projectile
    const auto projectiles = projectileController.getProjectiles();
    for (const auto &projectile: projectiles) {
        const int gridX = projectile.getPosition().left / (GRID_WIDTH / GRID_COLS);
        const int gridY = projectile.getPosition().top / (GRID_HEIGHT / GRID_ROWS);
        if (grid.isOccupied(gridX, gridY)) {
            grid.damageEntity(gridX, gridY);
            projectileController.removeProjectile(projectile);
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
