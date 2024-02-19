#ifndef SCENE_H
#define SCENE_H
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

using namespace sf;
class SceneManager;



class Scene: public Drawable{
public:
    ~Scene() override = default;

    virtual void handleInput(Event event, RenderWindow& window, SceneManager &sceneManager) {};

    virtual void update(float dt) {};

    void draw(RenderTarget& target, RenderStates states) const override {};
};



#endif //SCENE_H