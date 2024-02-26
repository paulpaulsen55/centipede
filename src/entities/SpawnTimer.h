#ifndef SPAWNTIMER_H
#define SPAWNTIMER_H

/**
 * The SpawnTimer class is responsible for handling the spawning of enemies.
 * It is responsible for keeping track of the time and determining when to spawn an enemy.
 */
class SpawnTimer {
public:
    explicit SpawnTimer(const float interval): interval(interval), time(0) {
    };

    void update(const float dt) {
        time += dt;
    }

    bool shouldSpawn() {
        if (time > interval) {
            time = 0;
            return true;
        }
        return false;
    }

    void reset() {
        time = 0;
    }

private:
    float interval;
    float time;
};


#endif //SPAWNTIMER_H
