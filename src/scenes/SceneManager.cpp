#include "SceneManager.h"

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

void SceneManager::addScene(std::unique_ptr<Scene> scene) {
    pushScene(std::move(scene));
}
