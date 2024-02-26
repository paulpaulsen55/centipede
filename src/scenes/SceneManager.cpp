#include "SceneManager.h"

SceneManager &SceneManager::getInstance() {
    static SceneManager instance;
    return instance;
}

void SceneManager::pushScene(std::unique_ptr<Scene> scene) {
    scenes.push(std::move(scene));
}

void SceneManager::popScene() {
    if (!scenes.empty()) {
        scenes.pop();
    }
}

void SceneManager::changeScene(std::unique_ptr<Scene> scene) {
    while (!scenes.empty()) {
        scenes.pop();
    }
    pushScene(std::move(scene));
}

Scene *SceneManager::getCurrentScene() const {
    if (!scenes.empty()) {
        return scenes.top().get();
    }
    return nullptr;
}
