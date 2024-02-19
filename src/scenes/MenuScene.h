#ifndef MENUSCENE_H
#define MENUSCENE_H
#include "Scene.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"

using namespace sf;



class MenuScene: public Scene{
public:
    MenuScene();

    void handleInput(RenderWindow& window) override;

    void update(float dt) override;

    void draw(RenderTarget& target, RenderStates states) const override;
private:
    Text title;

    RectangleShape startButton;
    Text startText;

    RectangleShape exitButton;
    Text exitText;

    Font font;
};



#endif //MENUSCENE_H
