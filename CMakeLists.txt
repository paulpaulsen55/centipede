cmake_minimum_required(VERSION 3.16)
project(Wormipede LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)

FetchContent_MakeAvailable(SFML)


add_executable(Wormipede src/main.cpp
        src/Player.cpp
        src/Player.h
        src/Projectile.cpp
        src/Projectile.h
        src/ProjectileController.cpp
        src/ProjectileController.h
        src/Game.cpp
        src/Game.h
        src/scenes/Scene.h
        src/scenes/SceneManager.cpp
        src/scenes/SceneManager.h
        src/scenes/MenuScene.cpp
        src/scenes/MenuScene.h
        src/scenes/GameOverScene.cpp
        src/scenes/GameOverScene.h
        src/scenes/GameScene.cpp
        src/scenes/GameScene.h
        src/Grid.cpp
        src/Grid.h
        src/entities/Entity.cpp
        src/entities/Entity.h
        src/entities/FlyEntity.cpp
        src/entities/FlyEntity.h
        src/entities/SpawnTimer.h
        src/TextureManager.cpp
        src/TextureManager.h
        src/entities/MushroomEntity.cpp
        src/entities/MushroomEntity.h
        src/Constants.h
        src/entities/worm/WormEntity.cpp
        src/entities/worm/WormEntity.h
        src/UtilityFunctions.h
        src/entities/worm/WormSegment.cpp
        src/entities/worm/WormSegment.h
        src/scenes/GameWinScene.cpp
        src/scenes/GameWinScene.h
        src/entities/SpiderEntity.cpp
        src/entities/SpiderEntity.h
)
file(COPY src/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
target_link_libraries(Wormipede PRIVATE sfml-graphics)
target_compile_features(Wormipede PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET Wormipede
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Wormipede>
        VERBATIM)
endif()

install(TARGETS Wormipede)
