#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "SceneManager.h"
#include "../Grid.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../Player.h"
#include "../ProjectileController.h"

using namespace sf;

/**
 * The GameScene class is responsible for handling the game loop of the game.
 * It is responsible for handling input, updating and drawing the game scene.
 */
class GameScene final : public Scene {
public:
    GameScene(int x, int y, TextureManager *textureManager);

    void handleInput(Event event, RenderWindow &window, SceneManager &sceneManager) override;

    void update(float dt) override;

    void draw(RenderTarget &target, RenderStates states) const override;

private:
    int x;
    int y;
    Player player;
    ProjectileController projectileController;
    float shootingDt{};
    Grid grid;
};


#endif //GAMESCENE_H
