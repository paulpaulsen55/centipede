#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H
#include "Scene.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"

using namespace sf;

/**
 * The GameOverScene class is responsible for handling the game over screen of the game.
 * It is responsible for handling input, updating and drawing the game over screen.
 */
class GameOverScene final : public Scene {
public:
    GameOverScene(int x, int y, TextureManager *textureManager);

    void handleInput(Event event, RenderWindow &window, SceneManager &sceneManager) override;

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
