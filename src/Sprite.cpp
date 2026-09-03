#define INCLUDE_SDL_IMAGE
#include "Sprite.h"
#include "SDL_include.h"
#include "Game.h"
#include <iostream>

Sprite::Sprite(){
    Sprite::texture = nullptr;
}

Sprite::Sprite(std::string file) {
    Sprite::texture = nullptr;
    Sprite::Open(file);

}

Sprite::~Sprite(){
    if (texture != nullptr){
    SDL_DestroyTexture(texture);
    }
}

void Sprite::Open(std::string file){
    if (IsOpen()) {
        SDL_DestroyTexture(texture);
    }
    texture = IMG_LoadTexture(Game::GetInstance("",0,0).GetRenderer(), file.c_str());
    if (!IsOpen()){
        std::cout << "IMG_LoadTexture probably returns nullptr" <<  '\n' << IMG_GetError() << std::endl;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height);
}
void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y){
    SDL_Renderer* renderer = Game::GetInstance("",0,0).GetRenderer();
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;
    SDL_RenderCopy(renderer, texture, &clipRect, &dstrect);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    return texture != nullptr;
}