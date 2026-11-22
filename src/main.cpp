#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_TTF
#include "SDL_include.h"
#include <iostream>
#include "Game.h"


int main (int argc, char** argv) {
    Game::GetInstance();
    std::cout << "ENRIKI ESTEVE AKI";
    Game::GetInstance().Run();
    return 0;
}
