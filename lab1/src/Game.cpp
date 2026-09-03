#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "Game.h"
#include "State.h"
#include "SDL_include.h"
#include <iostream>

// construtor
Game::Game(std::string title, int width, int height){
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        std::cout << "Error SDL_INIT:" << SDL_GetError() << std::endl;
    } //debug
    instance = this;

    //IMAGE
    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) != (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
        std::cout << "Error SDL_IMAGE:\n" << IMG_GetError() << std::endl;
    }

    //MIXER
    if (Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG) != (MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG)){
            std::cout << "Error SDL_MIXER:\n" << Mix_GetError() << std::endl;
        } // .wav é default
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) != 0){
        std::cout << "Error Mix_OpenAudio:\n" << Mix_GetError() << std::endl;
    }
    Mix_AllocateChannels(32);

    //WINDOW
    window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window == nullptr) {
        std::cout << "Error SDL_CreateWindow:" << SDL_GetError() << std::endl;
    }

    //RENDERER
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {

        std::cout << "Error SDL_CreateRenderer:" << SDL_GetError() << std::endl;
    }

    SDL_RenderSetLogicalSize(renderer,500,250);

    state = new State();
};

Game* Game::instance = nullptr;

// controle de instancia unica do jogo
Game& Game::GetInstance(std::string title, int width, int height){
    if (instance == nullptr){
        instance = new Game(title, width, height);
    }
        return *instance;
}


void Game::Run(){
    while (!GetState().QuitRequested()){
        GetState().Update(0);
        GetState().Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33); //1 frame por 33 ms, ~ 30FPS
    }
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

State& Game::GetState(){
    return *state;
}


