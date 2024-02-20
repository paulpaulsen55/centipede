#ifndef PROJECTILECONTROLLER_H
#define PROJECTILECONTROLLER_H
#include <list>
#include "Projectile.h"



class ProjectileController: public Drawable{
public:
    ProjectileController();

    void shootProjectile(float startX, float startY);

    std::list<Projectile> getProjectiles();

    void updateProjectiles();

private:
    void draw(RenderTarget &target, RenderStates states) const override;

    std::list<Projectile> projectiles;
};



#endif //PROJECTILECONTROLLER_H
