#include "SpriteRenderer.h"
#include "Sprite.h"
#include <string>

SpriteRenderer::SpriteRenderer(GameObject& associated) : Component(associated){
    Sprite();

}


SpriteRenderer::SpriteRenderer(GameObject& associated, std::string file, int frameCountW, int frameCountH) : Component(associated), sprite(file, frameCountW, frameCountH){
    associated.box.w = sprite.GetWidth();
    associated.box.h = sprite.GetHeight();
    sprite.SetFrame(0);
}

void SpriteRenderer::Update(float dt){

}

void SpriteRenderer::Render(){
    sprite.Render(associated.box.x,associated.box.y,associated.box.w,associated.box.h);
}

void SpriteRenderer::Open(std::string file){
    sprite.Open(file);
}

void SpriteRenderer::SetFrame(int frame) {
    sprite.SetFrame(frame);
}