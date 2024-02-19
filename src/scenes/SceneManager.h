#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <memory>
#include <stack>

#include "Scene.h"



class SceneManager {
public:
    void pushScene(std::unique_ptr<Scene> scene);

    void popScene();

    void changeScene(std::unique_ptr<Scene> scene);

    [[nodiscard]] Scene* getCurrentScene() const;

private:
    std::stack<std::unique_ptr<Scene>> scenes;
};



#endif //SCENEMANAGER_H
