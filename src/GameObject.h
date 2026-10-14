#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Component.h"
#include <vector>
#include "Rect.h"

class GameObject{
    public:
        GameObject();
        ~GameObject();
        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        
        T* GetComponent();
        template <typename T>
        Rect box;
    private:
        std::vector <Component*> components;
        bool isDead;
};

template <typename T>
T* GameObject::GetComponent() {
    for (Component* cpt : components) {
        T* casted = dynamic_cast<T*>(cpt);
        if (casted != nullptr) {
            return casted;
        }
    }
    return nullptr;
}

#endif