#define INCLUDE_SDL_MIXER
#include "Music.h"

#include "SDL_include.h"
#include <iostream>


Music::Music(){
    music = nullptr;
}

Music::Music(std::string file){
    Open(file);
}

void Music::Play(int times){
    Mix_PlayMusic(music, times); //loops = -1: infinito
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
    music = Mix_LoadMUS(file.c_str());
    if (!music){
        std::cout << "Mix Music null\n" << Mix_GetError() << std::endl;
    }
}


bool Music::IsOpen(){
    return music != nullptr;
}

Music::~Music(){
    Stop(0);
    Mix_FreeMusic(music);

}