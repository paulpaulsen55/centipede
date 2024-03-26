#ifndef GAMEWINSCENE_H
#define GAMEWINSCENE_H
#include "Scene.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"


class GameWinScene final : public Scene{
public:
    explicit GameWinScene(int score);

    void handleInput(Event event, RenderWindow &window) override;

    void update(float dt) override;

    void draw(RenderTarget &target, RenderStates states) const override;

private:
    Sprite background;
    Texture texture;

    Text scoreText;
    int score;

    RectangleShape menuButton;
    Text menuText;

    Font font;

};



#endif //GAMEWINSCENE_H
