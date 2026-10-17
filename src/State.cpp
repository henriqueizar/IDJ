#include "State.h"
#include "SDL_include.h"
#include <iostream>

State::State(){
    quitRequested = false;
    bg.Open("./assets/img/Background.png");
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
    bg.Render(0,0);
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

