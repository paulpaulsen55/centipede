#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <memory>

#include "Scene.h"



class SceneManager {
public:
    void pushScene(std::unique_ptr<Scene> scene);

    void popScene();

    void changeScene(std::unique_ptr<Scene> scene);

    Scene* getCurrentScene() const;

private:
    std::vector<std::unique_ptr<Scene>> scenes;
};



#endif //SCENEMANAGER_H
