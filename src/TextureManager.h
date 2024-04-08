#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>
#include <string>

#include "SFML/Graphics/Texture.hpp"

using namespace sf;

/**
 * The `TextureManager` class is responsible for managing textures of Sprites.
 * It provides methods for loading, retrieving textures and ensures that textures dont get unloaded.
 * This allows for a centralized way of managing all textures used in the application.
 */
class TextureManager {
public:
    static TextureManager &getInstance();

    void loadTexture(const std::string &path);

    Texture &getTexture(const std::string &path);

private:
    std::map<std::string, Texture> textures;
};


#endif //TEXTUREMANAGER_H
