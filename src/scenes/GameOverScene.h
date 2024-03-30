#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H
#include "Scene.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"

using namespace sf;

/**
 * The `GameOverScene` class is responsible for handling the game over screen of the game.
 * It is responsible for handling input, updating and drawing the game over screen.
 */
class GameOverScene final : public Scene {
public:
    GameOverScene();

    void handleInput(Event event, RenderWindow &window) override;

    void update(float dt) override;

    void draw(RenderTarget &target, RenderStates states) const override;

private:
    Sprite background;
    Texture texture;

    RectangleShape restartButton;
    Text restartText;

    RectangleShape menuButton;
    Text menuText;

    Font font;
};


#endif //GAMEOVERSCENE_H
