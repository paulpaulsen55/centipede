#include "GameScene.h"

#include "GameOverScene.h"
#include "GameWinScene.h"
#include "MenuScene.h"
#include "../Constants.h"
#include "SFML/Window/Event.hpp"

GameScene::GameScene() : player(x / 2 - 11, y - 120) {
    TextureManager::getInstance().loadTexture("assets/scenes/gamebg.png");
    background.setTexture(TextureManager::getInstance().getTexture("assets/scenes/gamebg.png"));
    background.setPosition(0, 595);

    TextureManager::getInstance().loadTexture("assets/heart.png");
    Sprite heart;
    heart.setTexture(TextureManager::getInstance().getTexture("assets/heart.png"));
    const float heartWidth = heart.getGlobalBounds().width;

    for (int i = 0; i < lives; i++) {
        heart.setPosition(10 + i * (heartWidth + 10), 652);
        hearts.push_back(heart);
    }

    font.loadFromFile(FONT);
    score.setFont(font);
    score.setCharacterSize(64);
    score.setFillColor(slate800);
    score.setStyle(Text::Bold);
    score.setString("0");
    score.setPosition(x - score.getGlobalBounds().width - 20, 632);
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
    // check for winning condition
    if (!grid.worm.isAlive()) {
        SceneManager::getInstance().changeScene(std::make_unique<GameWinScene>(scoreValue));
        return;
    }
    // check for losing condition
    if (lives == 0) {
        SceneManager::getInstance().changeScene(std::make_unique<GameOverScene>());
        return;
    }

    // check if a entity is hit by a projectile
    const auto projectiles = projectileController.getProjectiles();
    for (const auto &projectile: projectiles) {
        const int gridY = projectile.getPosition().top / (GRID_HEIGHT / GRID_ROWS) - 1;
        const int gridX = (GRID_COLS - 1) * (projectile.getPosition().left - 1) / x;
        if (grid.isOccupied(gridX, gridY)) {
            if (grid.isOccupiedByWorm(gridX, gridY)) {
                grid.worm.damage();
                scoreValue += 200;
            } else {
                grid.damageEntity(gridX, gridY);
                scoreValue += 25;
            }
            projectileController.removeProjectile(projectile);
            score.setString(std::to_string(scoreValue));
            score.setPosition(x - score.getGlobalBounds().width - 10, 632);
        }
    }

    this->shootingDt += dt;

    // if a entity reaches the bottom of the screen, the player loses a life
    for (int i = 0; i < GRID_COLS; i++) {
        if (grid.isOccupied(i, GRID_ROWS - 2)) {
            grid.removeEntity(i, GRID_ROWS - 2);
            lives--;
            hearts.pop_back();
        }
    }

    // player movement collision with borders
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
    target.draw(background);
    target.draw(score);

    for (const auto &heart: hearts) {
        target.draw(heart);
    }

    target.draw(grid);
    target.draw(player);
    target.draw(projectileController);
}
