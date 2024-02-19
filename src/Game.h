#ifndef GAME_H
#define GAME_H
#include "GameState.h"
#include "Player.h"
#include "ProjectileController.h"
#include "scenes/SceneManager.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

using namespace sf;



class Game {
private:
    RenderWindow *window;
    SceneManager *sceneManager;
    GameState gameState;
    Event event{};
    Clock clock;
    float dt{};
    Time minFrameTime = seconds(1.f / 30.f);
    Player player;
    ProjectileController projectileController;

    float gridSize{};

    void processEvent() const;

    void reset();

    void update(Time dt);

    void render() const;

public:
    Game(int x = 800, int y = 600);

    void run();

    void initLevel();
};
#endif //GAME_H
