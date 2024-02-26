#ifndef MENUSCENE_H
#define MENUSCENE_H
#include "Scene.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"

using namespace sf;

/**
 * The MenuScene class is responsible for handling the main menu of the game.
 * It is responsible for handling input, updating and drawing the main menu.
 */
class MenuScene final : public Scene {
public:
    MenuScene();

    void handleInput(Event event, RenderWindow &window) override;

    void update(float dt) override;

    void draw(RenderTarget &target, RenderStates states) const override;

private:
    Text title;

    RectangleShape startButton;
    Text startText;

    RectangleShape exitButton;
    Text exitText;

    Font font;
};


#endif //MENUSCENE_H
