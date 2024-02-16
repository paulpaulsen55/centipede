#include "ProjectileController.h"

ProjectileController::ProjectileController() {
}

void ProjectileController::shootProjectile(float startX, float startY) {
    Projectile newProjectile(startX, startY);
    projectiles.push_back(newProjectile);
}

std::list<Projectile> ProjectileController::getProjectiles() {
    return projectiles;
}

void ProjectileController::updateProjectiles() {
    for (auto &projectile : projectiles) {
        projectile.update();
    }
}
