#ifndef SPAWNTIMER_H
#define SPAWNTIMER_H



class SpawnTimer {
public:
    SpawnTimer(const float interval): interval(interval), time(0) {};

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

private:
    float interval;
    float time;
};



#endif //SPAWNTIMER_H
