#include "GameObject.h"

GameObject::GameObject(): isDead(false) {
}

GameObject::~GameObject(){
    for (int i = components.size();i>0;i--){
        delete components[i-1];
    }
    components.clear();
}

void GameObject::Update(float dt){
    for (int i = 0;i < (int)components.size();i++){
        components[i]->Update(dt);
    }
}

void GameObject::Render(){
    for (int i = 0;i < (int)components.size();i++){
        components[i]->Render();
    }
}

bool GameObject::IsDead() {
    return isDead;
}

void GameObject::RequestDelete() {
    isDead = true;
}

void GameObject::AddComponent(Component* cpt) {
    components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt) {
    for (int i = 0; i < (int)components.size(); i++) {
        if (components[i] == cpt) {
            components.erase(components.begin() + i);
            return;
        }
    }
}