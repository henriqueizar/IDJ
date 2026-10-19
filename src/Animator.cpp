#include "Animator.h"
#include "GameObject.h"

#include "SpriteRenderer.h"

Animator::Animator(GameObject& associated) : Component(associated), frameEnd(0), frameStart(0), frameTime(0), timeElapsed(0){

}

void Animator::Update(float dt){
    if (frameTime == 0) {
        return;
    } else{
        ++timeElapsed;
        if (timeElapsed >= frameTime){
            ++currentFrame;
            timeElapsed -= frameTime;
            if (currentFrame > frameEnd){
                currentFrame = frameStart;
            }
            SpriteRenderer* sr = associated.GetComponent<SpriteRenderer>();
            sr->SetFrame(currentFrame);
        }
    }
}

void Animator::Render(){
    //vazio
}

void Animator::SetAnimation(std::string name){
    auto it = animations.find(name);

    if (it != animations.end()){
        frameStart = it->second.frameStart;
        frameEnd = it->second.frameEnd;
        frameTime = it->second.frameTime;
        currentFrame = frameStart;
        timeElapsed = 0;
        SpriteRenderer* sr = associated.GetComponent<SpriteRenderer>();
        sr->SetFrame(currentFrame);
    }

}

void Animator::AddAnimation(std::string name, Animation anim){
    //Busque no seu unordered_map por um par com chave = name. Se não
//ncontrar, insira o par (name, anim) no seu mapa.
    auto it = animations.find(name);
    if (it == animations.end()){
        animations.emplace(name, anim);
    }
}