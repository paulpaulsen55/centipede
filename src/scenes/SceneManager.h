#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <memory>
#include <stack>

#include "Scene.h"
#include "../TextureManager.h"

/**
 * The `SceneManager` class is responsible for managing the scenes in the game.
 * It provides methods for pushing, popping and changing scenes.
 * This allows for different scenes in the game, such as the main menu, the game itself and the game over screen.
 * NOTE: At this point only one scene can be active at a time. Maybe support multiple scenes in the future e.g. Upgrade Menu ;).
 */
class SceneManager {
public:
    static SceneManager &getInstance();

    void pushScene(std::unique_ptr<Scene> scene);

    void popScene();

    void changeScene(std::unique_ptr<Scene> scene);

    [[nodiscard]] Scene *getCurrentScene() const;

private:
    std::stack<std::unique_ptr<Scene> > scenes;
};


#endif //SCENEMANAGER_H
