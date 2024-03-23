#ifndef GAMEWINSCENE_H
#define GAMEWINSCENE_H
#include "Scene.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"


class GameWinScene final : public Scene{
public:
    explicit GameWinScene(int score);

    void handleInput(Event event, RenderWindow &window) override;

    void update(float dt) override;

    void draw(RenderTarget &target, RenderStates states) const override;

private:
    Text winText;

    RectangleShape menuButton;
    Text menuText;

    Font font;

    int score;
};



#endif //GAMEWINSCENE_H
