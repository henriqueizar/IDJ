#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_TTF
#include "SDL_include.h"
#include <iostream>
#include "Game.h"
#

int main (int argc, char** argv) {
    Game::GetInstance("Henrique Izar 222026985", 1200, 900);
    std::cout << "ENRIKI ESTEVE AKI";
    return 0;
}
