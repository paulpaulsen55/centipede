#include "Game.h"
#ifdef _MSC_VER
    #include <windows.h>
#endif

using namespace sf;

int main(int argc, char* argv[]) {
    Game game;
    game.run();
}

// this is a workaround to make the game run on Windows without a console window
#ifdef _MSC_VER
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
    {
        return main(__argc, __argv);
    }
#endif