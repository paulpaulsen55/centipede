#ifndef ENTITY_H
#define ENTITY_H



class Entity {
public:
    Entity(int x, int y);
    virtual void move();

protected:
    int x;
    int y;
};



#endif //ENTITY_H
