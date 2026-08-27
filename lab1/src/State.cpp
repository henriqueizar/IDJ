#include "State.h"
#include "SDL_include.h"
#include <iostream>

State::State(){
    quitRequested = false;
    //bg = new Sprite();
}

void State::Update(float dt){
    if (SDL_QuitRequested()) {
        quitRequested = true;
        std::cout << "Quit request" << std::endl;
    }
}

void State::Render(){
    // bg.Render(0,0);
}

void State::LoadAssets(){ //pré carrega os assets

}

bool State::QuitRequested(){
    return quitRequested;
}