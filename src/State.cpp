#include "State.h"
#include "SDL_include.h"
#include <iostream>
#include "SpriteRenderer.h"
#include "Bixo.h"

State::State(){
    quitRequested = false;
    GameObject* go_bg = new GameObject();
    SpriteRenderer* sr_bg = new SpriteRenderer(*go_bg, "./assets/img/Background.png");
    go_bg->AddComponent(sr_bg);
    AddObject(go_bg);
    GameObject* go = new GameObject();
    Bixo* bixo = new Bixo(*go);
    go->AddComponent(bixo);
    go->box.x = 100;
    go->box.y = 150;
    AddObject(go);

    music.Open("./assets/audio/memo.wav");
    music.Play();
}

State::~State(){
    objectArray.clear();
}

void State::Update(float dt){
    if (SDL_QuitRequested()) {
        quitRequested = true;
        std::cout << "Quit request" << std::endl;
    }

    for (int i=0; i < objectArray.size();i++){
        objectArray[i]->Update(dt);
    }
    for (int i = (int)objectArray.size() - 1; i >= 0; i--) {
        if (objectArray[i]->IsDead()) {
        objectArray.erase(objectArray.begin() + i);
        }
    }
}

void State::Render(){
    for (int i=0; i < objectArray.size();i++){
        objectArray[i]->Render();
    }
}

void State::LoadAssets(){ //pré carrega os assets

}

bool State::QuitRequested(){
    return quitRequested;
}

void State::AddObject(GameObject* go){
    objectArray.emplace_back(go);
}

