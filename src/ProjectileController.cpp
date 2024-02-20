#include "ProjectileController.h"
#include "SFML/Graphics/RenderTarget.hpp"


ProjectileController::ProjectileController() {
}

void ProjectileController::shootProjectile(const float startX, const float startY) {
    const Projectile newProjectile(startX, startY);
    projectiles.push_back(newProjectile);
}

std::list<Projectile> ProjectileController::getProjectiles() {
    return projectiles;
}

void ProjectileController::updateProjectiles() {
    auto it = projectiles.begin();
    while (it != projectiles.end()) {
        if (it->getPosition().top < 0) {
            it = projectiles.erase(it);
        } else {
            it->update();
            ++it;
        }
    }
}

void ProjectileController::draw(RenderTarget &target, RenderStates states) const {
    for (auto projectile : projectiles) {
        target.draw(projectile.getShape());
    }
}
