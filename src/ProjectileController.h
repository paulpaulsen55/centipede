#ifndef PROJECTILECONTROLLER_H
#define PROJECTILECONTROLLER_H
#include <list>
#include "Projectile.h"


/**
 * The `ProjectileController` class is responsible for managing the projectiles in the game.
 * It provides methods for creating new projectiles and removes them when they are out of view.
 */
class ProjectileController final : public Drawable {
public:
    ProjectileController();

    ~ProjectileController() override = default;

    void shootProjectile(float startX, float startY);

    std::list<Projectile> getProjectiles();

    void updateProjectiles();

    void removeProjectile(const Projectile &projectile);

private:
    void draw(RenderTarget &target, RenderStates states) const override;

    std::list<Projectile> projectiles;
};


#endif //PROJECTILECONTROLLER_H
