#include "TextureManager.h"

#include <stdexcept>

using namespace sf;

void TextureManager::loadTexture(const std::string &name, const std::string &filename) {
    Texture texture;
    if (!texture.loadFromFile(filename)) {
        throw std::runtime_error("Error loading texture: " + filename + ".");
    }

    this->textures[name] = texture;
}

Texture &TextureManager::getTexture(const std::string &name) {
    const auto texture = this->textures.find(name);
    if (texture == this->textures.end()) {
        throw std::runtime_error("TextureManager::getTexture - Texture " + name + " not found.");
    }

    return texture->second;
}
