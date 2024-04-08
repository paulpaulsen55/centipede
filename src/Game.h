#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "ProjectileController.h"
#include "scenes/SceneManager.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

using namespace sf;

/**
 * The `Game` class is the main class (entry point) of the game.
 * It provides methods for running the game loop and handling events.
 * The main window and the scene manager are also included.
 */
class Game {
public:
    Game();

    void run();

private:
    RenderWindow *window;
    SceneManager *sceneManager;
    Event event{};
    Clock clock;
    float dt{};
    Time minFrameTime = seconds(1.f / 30.f);

    float gridSize{};

    void processEvent() const;

    void update(Time dt) const;

    void render() const;
};

#endif //GAME_H
