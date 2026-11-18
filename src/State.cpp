#include "State.h"
#include "SDL_include.h"
#include <iostream>
#include "SpriteRenderer.h"
#include "Bixo.h"
#include "TileMap.h"
#include "InputManager.h"

State::State(){
    quitRequested = false;
    GameObject* go_bg = new GameObject();
    SpriteRenderer* sr_bg = new SpriteRenderer(*go_bg, "./assets/img/Backgroud2.png");
    go_bg->AddComponent(sr_bg);
    
    /*GameObject* go_bixo = new GameObject();
    Bixo* bixo = new Bixo(*go_bixo);
    go_bixo->AddComponent(bixo);
    go_bixo->box.x = 100;
    go_bixo->box.y = 100;*/

    /*GameObject* go_bixo2 = new GameObject();
    Bixo* bixo2 = new Bixo(*go_bixo2);
    go_bixo2->AddComponent(bixo2);
    go_bixo2->box.x = 200;
    go_bixo2->box.y = 80;*/
    

    GameObject* go_map = new GameObject();
    go_map->box.x = 0;
    go_map->box.y = 0;


    TileSet* ts = new TileSet(16,16,"./assets/img/tileset.png");
    TileMap* tm = new TileMap(*go_map,"./assets/map/map.txt",ts);
    go_map->AddComponent(tm);
    

    music.Open("./assets/audio/memo.wav");
    music.Play();

    //EM ORDEM:
    AddObject(go_bg); 
    AddObject(go_map);
    //AddObject(go_bixo);
    //AddObject(go_bixo2);
}

State::~State(){
    objectArray.clear();
}

void State::Update(float dt){
    if (InputManager::GetInstance().KeyPress(ESCAPE_KEY) || InputManager::GetInstance().QuitRequested()){
        quitRequested = true;
        std::cout << "Quit via ESC" << std::endl;
    }

    for (int i=0; i < objectArray.size();i++){
        objectArray[i]->Update(dt);
    }
    for (int i = (int)objectArray.size() - 1; i >= 0; i--) {
        if (objectArray[i]->IsDead()) {
        objectArray.erase(objectArray.begin() + i);
        }
    }
    if (InputManager::GetInstance().KeyPress(' ')){
        std::cout<<"ESPACE";
        GameObject* go_bixo = new GameObject();
        Bixo* bixo = new Bixo(*go_bixo);
        go_bixo->AddComponent(bixo);
        go_bixo->box.x = InputManager::GetInstance().GetMouseX();
        go_bixo->box.y = InputManager::GetInstance().GetMouseY();
        AddObject(go_bixo);
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

