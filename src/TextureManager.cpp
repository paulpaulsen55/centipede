#include "TextureManager.h"

#include <stdexcept>

using namespace sf;

TextureManager &TextureManager::getInstance() {
    static TextureManager instance;
    return instance;
}

void TextureManager::loadTexture(const std::string &path) {
    if (this->textures.find(path) != this->textures.end()) {
        return;
    }
    Texture texture;
    if (!texture.loadFromFile(path)) {
        throw std::runtime_error("Error loading texture: " + path + ".");
    }

    this->textures[path] = texture;
}

Texture &TextureManager::getTexture(const std::string &path) {
    const auto texture = this->textures.find(path);
    if (texture == this->textures.end()) {
        throw std::runtime_error(
            "TextureManager::getTexture - Texture " + path + " not found. Maybe you forgot to load it?");
    }

    return texture->second;
}
