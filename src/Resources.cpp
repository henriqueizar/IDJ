#include "Resources.h"
#include <iostream>
#include "Game.h"


// Definiçao dos atributos static do .h (para alocá-los na memória)
std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*>   Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*>   Resources::soundTable;


SDL_Texture* Resources::GetImage(std::string file){
    auto it = imageTable.find(file);
    if (it != imageTable.end()){
        return it->second;  //resgata do cache
    }
    SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance("", 0, 0).GetRenderer(), file.c_str());
    if (texture == nullptr) {
        std::cerr << "Resources: failed to load " << file << "\n" << IMG_GetError() << std::endl;
        return nullptr;                          // failure handling
    }
    imageTable[file] = texture;        //guarda (cache)
    return texture;
}

void Resources::ClearImages(){
    for (auto& pair : imageTable){
        SDL_DestroyTexture(pair.second);
    }
    imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file){
    auto it = musicTable.find(file);
    if (it != musicTable.end()){
        return it->second;  //resgata do cache
    }
    Mix_Music* music = Mix_LoadMUS(file.c_str());
    if (music == nullptr) {
        std::cerr << "Resources: failed to load " << file << "\n" << Mix_GetError() << std::endl;
        return nullptr;                          // don't cache failures
    }

    musicTable[file] = music;                    // cache it
    return music;
}

void Resources::ClearMusics(){
    for (auto& pair : musicTable) {
        Mix_FreeMusic(pair.second);
    }
    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(std::string file){
    auto it = soundTable.find(file);
    if (it != soundTable.end()){
        return it->second;  //resgata do cache
    }
    Mix_Chunk* chunk = Mix_LoadWAV(file.c_str());
    if (chunk == nullptr) {
        std::cerr << "Resources: failed to load " << file << "\n" << Mix_GetError() << std::endl;
        return nullptr;                          // don't cache failures
    }

    soundTable[file] = chunk;                    // cache it
    return chunk;
}

void Resources::ClearSounds(){
    for (auto& pair : soundTable) {
        Mix_FreeChunk(pair.second);
    }
    soundTable.clear();
}