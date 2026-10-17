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

void Sprite::Render(int x, int y, int w, int h){
    SDL_Renderer* renderer = Game::GetInstance("",0,0).GetRenderer();
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = w;
    dstrect.h = h;
    SDL_RenderCopy(renderer, texture, &clipRect, &dstrect);
}

int Sprite::GetWidth(){
    return width/frameCountW;
}

int Sprite::GetHeight(){
    return height/frameCountH;
}

bool Sprite::IsOpen(){
    return texture != nullptr;
}

void Sprite::SetFrame(int frame){
    if (frame < 0 || frame > frameCountW * frameCountH){
        std::cout<<"Sprite: frame out of range"<<std::endl;
        std::cerr;
    } else{
    int x = (frame % frameCountW) * (width / frameCountW);
    int y = (frame / frameCountW) * (height / frameCountH);
    int w = width/frameCountW;
    int h = height/frameCountH;
    SetClip(x,y, w, h);
    }
}

void Sprite::SetFrameCount(int frameCountW, int frameCountH){
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
}

