# Wormipede

Wormipede is a game inspired by the 1981 classic Centipede. You are a wizard in search of the magical hibiscus flower.
You have heard of its powers, when brewed into a potion, to vanquish all the evil insects from your garden. After hours
of searching through the dark forest, you finally find the flower. But when you return home and enter your garden, the
ground beneath you begins to tremble. The worm is awakening! You must stop the worm and other insects from reaching the
flower and destroying it. Use your magic to stop them!

## How to play

- Navigate the menus by clicking the buttons with the mouse
- Move the player with the arrow keys
- Shoot with the space key
- Stop the insects and worm from reaching the bottom of the screen

## Prerequisites

- CMake

## Build

_TODO: Test build_

```bash
mkdir build
cd build
cmake ..
make
```

## Development

The game is written in C++ using the SFML2 library for graphics and input handling. The game is structured using a
scene-based architecture, where each scene represents a different screen in the game, such as the main menu, gameplay
and game-over screens. These are managed using the `SceneManager` class. The game loop is controlled by the `Game` class,
which updates and renders the current scene. The gameplay logic is contained in the `GameplayScene` class, which handles
player movement, entity movement, bullet firing and collision detection. The player character is represented by
the `Player` class. All of the enemy entities are represented by a class of their own, which inherits from the `Entity`
class. All entities are placed on a grid represented by the `Grid` class, which handles collision detection and entity
movement. The player can also fire projectiles to destroy enemy entities, which are represented by the `Projectile`
class and managed by the `ProjectileController` class. Because of the dynamic entity creation, the `TextureManager`
class is used to load and store textures for the entities. 
The game is built using the CMake build system, which allows for easy compilation and linking of the game code and dependencies.

### Class Hierarchy


## Known Issues
- The worm sometimes goes down two spaces, which causes the tail to orientate incorrectly