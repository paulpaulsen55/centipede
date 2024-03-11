#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

#include "SFML/Graphics/Color.hpp"


using namespace sf;

// UI constants
const std::string FONT = "assets/baloo2.ttf";
const auto blue700 = Color(3, 105, 161);
const auto slate800 = Color(30, 41, 59);

// Player constants
constexpr float PLAYER_SPEED = 1.5f;

// Projectile constants
constexpr float PROJECTILE_SPEED = 3.0f;
constexpr float PROJECTILE_COOLDOWN = 0.3f;

// Grid constants
constexpr int GRID_WIDTH = 800;
constexpr int GRID_HEIGHT = 600;
constexpr int GRID_COLS = 32;
constexpr int GRID_ROWS = 24;
constexpr int MUSHROOM_SPAWNCHANCE = 4;

// Entity constants
constexpr int WORM_LENGTH = 10;


#endif //CONSTANTS_H
