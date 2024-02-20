#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "SceneManager.h"
#include "../Grid.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../Player.h"
#include "../ProjectileController.h"

using namespace sf;



class GameScene: public Scene{
public:
    GameScene(int x, int y);

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
