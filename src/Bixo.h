#ifndef BIXO_H
#define BIXO_H
#include "GameObject.h"
#include "Sound.h"
#include "Animator.h"

class Bixo : public Component{
    public:
        Bixo(GameObject& associated);
        void Grab(/*GameObject& item*/);
        void Update(float dt);
        void Render();
    private:
        int hitpoints;
        float speed;
        int direction = 1;
        Sound* step_sound;
        Animator* anim = nullptr;
        bool grabbing = false; //vai virar uma maquina de estados futuramente
};

#endif