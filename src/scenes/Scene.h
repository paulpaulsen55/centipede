#ifndef SCENE_H
#define SCENE_H
#include "../TextureManager.h"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

using namespace sf;
class SceneManager;

/**
 * The Scene class is an abstract class that represents a scene in the game.
 * It is responsible for handling input, updating and drawing the scene.
 */
class Scene : public Drawable {
public:
    virtual void handleInput(Event event, RenderWindow &window, SceneManager &sceneManager) = 0;

    virtual void update(float dt) = 0;

    void draw(RenderTarget &target, RenderStates states) const override = 0;
};


#endif //SCENE_H
