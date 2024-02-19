#include "SceneManager.h"

void SceneManager::pushScene(std::unique_ptr<Scene> scene) {
    scenes.push_back(std::move(scene));
}

void SceneManager::popScene() {
    if (!scenes.empty()) {
        scenes.pop_back();
    }
}

void SceneManager::changeScene(std::unique_ptr<Scene> scene) {
    popScene();
    pushScene(std::move(scene));
}

Scene * SceneManager::getCurrentScene() const {
    if (!scenes.empty()) {
        return scenes.back().get();
    }
    return nullptr;
}
