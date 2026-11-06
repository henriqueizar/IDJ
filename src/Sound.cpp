#include "Sound.h"
#include <iostream>

Sound::Sound() : chunk(nullptr), channel(-1){
}

Sound::Sound(std::string file) : Sound(){
    Open(file);
}

void Sound::Play(int times){
    if (chunk == nullptr) return;
    //mixer aloca um canal pro som (-1)
    channel = Mix_PlayChannel(-1, chunk, times);
    if (channel == -1) {
        std::cerr << "Error playing sound: " << Mix_GetError() << std::endl;
    }
}

void Sound::Stop(){
    if (chunk != nullptr && channel >= 0){
    Mix_HaltChannel(channel);
    }
    //std::cout<<"STOP SOUND"<<std::endl;
}

void Sound::Open(std::string file){
    chunk = Mix_LoadWAV(file.c_str());
    if (chunk == nullptr){
        std::cout<< "Error Sound Opening: \n" << file << "\n" << Mix_GetError() << std::endl;
    };
    std::cout<<"Sound Opened:" + file <<std::endl;
}

Sound::~Sound(){
    
    if (chunk != nullptr){
        Mix_HaltChannel(channel);
        Mix_FreeChunk(chunk);
    }
    //std::cout<<"STOP SOUND"<<std::endl;
}
bool Sound::IsOpen(){
    return chunk != nullptr;
}