#ifndef SCENE_H
#define SCENE_H
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

using namespace sf;



class Scene: public Drawable{
public:
    ~Scene() override = default;

    virtual void handleInput(RenderWindow& window) {};

    virtual void update(float dt) {};

    void draw(RenderTarget& target, RenderStates states) const override {};
};



#endif //SCENE_H