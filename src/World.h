#ifndef WORLD_H
#define WORLD_H
#include "SFML/Graphics/Drawable.hpp"

using namespace sf;



class World: public Drawable {
private:
    int x;
    int y;

    void draw(RenderTarget& target, RenderStates states) const override;

public:
    World(int x, int y);

    void update();
};



#endif //WORLD_H
