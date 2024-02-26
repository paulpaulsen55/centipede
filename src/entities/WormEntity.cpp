/*#include "WormEntity.h"

#include "MushroomEntity.h"
#include "../TextureManager.h"
#include "../Projectile.h"


WormEntity::WormEntity(): Entity("assets/wormhead.png") {
}

WormEntity::WormEntity(int x, int y, std::vector<Entity *> segments): Entity("assets/wormhead.png"), segments(segments) {
}

void WormEntity::move() {
}

void WormEntity::handleCollision(Entity *other) {
    const MushroomEntity* mushroom = dynamic_cast<MushroomEntity*>(other);
    if (mushroom) {
        // If the other entity is a mushroom, move the worm down a line
        this->y += 1;
    } else {
        // If the other entity is not a mushroom, check if it's a segment of the worm
        for (int i = 0; i < segments.size(); i++) {
            if (segments[i] == other) {
                // If a segment is hit, split the worm into two parts
                std::vector<Entity *> firstHalf(segments.begin(), segments.begin() + i);
                std::vector<Entity *> secondHalf(segments.begin() + i + 1, segments.end());

                // Create two new worms from the split segments
                WormEntity firstWorm(this->x, this->y, firstHalf);
                WormEntity secondWorm(this->x, this->y, secondHalf);

                // Replace the current worm with the two new worms
                // This will depend on your game logic
                break;
            }
        }
    }
}

void WormEntity::damage() {
}
*/