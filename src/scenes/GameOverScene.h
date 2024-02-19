#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H
#include "Scene.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"

using namespace sf;



class GameOverScene: public Scene{
public:
    GameOverScene(int x, int y);

    void handleInput(RenderWindow &window, SceneManager &sceneManager) override;

    void update(float dt) override;

    void draw(RenderTarget &target, RenderStates states) const override;

private:
    int x;
    int y;

    Text gameOverText;

    RectangleShape restartButton;
    Text restartText;

    Font font;
};



#endif //GAMEOVERSCENE_H
