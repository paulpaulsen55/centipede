#ifndef PROJECTILECONTROLLER_H
#define PROJECTILECONTROLLER_H
#include <list>

#include "Projectile.h"


class ProjectileController {

private:
    std::list<Projectile> projectiles;

public:
    ProjectileController();

    void shootProjectile(float startX, float startY);

    std::list<Projectile> getProjectiles();

    void updateProjectiles();
};



#endif //PROJECTILECONTROLLER_H
