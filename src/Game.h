#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

using namespace sf;


class Game {
private:
    RenderWindow *window;
    Event event;
    Clock clock;
    float dt;
    Time minFrameTime = seconds(1.f / 30.f);

    float gridSize;

    void processEvent();

    void initWindow();

    void initKeys();

    void initPlayer();

    void reset();

    void update(Time dt);

    void render();

public:
    Game(const Game&) = delete;

    Game& operator=(const Game&) = delete;

    Game(int x = 800, int y = 600);

    void run();

    void initLevel();
};



#endif //GAME_H
