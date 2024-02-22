#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <map>
#include <string>

#include "SFML/Graphics/Texture.hpp"

using namespace sf;


class TextureManager {
public:
    void loadTexture(const std::string& name, const std::string& filename);

    Texture &getTexture(const std::string& name);

private:
    std::map<std::string, Texture> textures;

};


#endif //TEXTUREMANAGER_H
