#ifndef SCENE_H
#define SCENE_H
#include "../TextureManager.h"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

using namespace sf;
class SceneManager;

/**
 * The Scene class is an abstract class that represents a scene in the game.
 * It is responsible for handling input, updating and drawing the scene.
 */
class Scene : public Drawable {
public:
    TextureManager *textureManager;

    explicit Scene(TextureManager *textureManager) : textureManager(textureManager) {
    };

    ~Scene() override = default;

    virtual void handleInput(Event event, RenderWindow &window, SceneManager &sceneManager) {
    };

    virtual void update(float dt) {
    };

    void draw(RenderTarget &target, RenderStates states) const override {
    };

private:
};


#endif //SCENE_H
