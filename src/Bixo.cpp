#include "Bixo.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include <iostream>
#include "Animator.h"

Bixo::Bixo(GameObject& associated) : Component(associated), hitpoints(100), speed(2.0f){
    SpriteRenderer* sr = new SpriteRenderer(associated, "./assets/img/bixo_andando-Sheet.png", 4, 4);
    associated.AddComponent(sr);
    associated.box.w = 48;
    associated.box.h = 48;
    anim = new Animator(associated);
    anim->AddAnimation("walking",Animation(0,13,2));
    associated.AddComponent(anim);
    anim->SetAnimation("walking");
    step_sound = new Sound("./assets/audio/passo.wav");
    
}

void Bixo::Damage(int damage) {
    hitpoints -= damage;
    if (hitpoints > -300){
        SpriteRenderer* sr = associated.GetComponent<SpriteRenderer>();
        //sr -> SetFrame(10);
        if (direction == 1){
            associated.box.x += speed;
                if (associated.box.x >=280){
                    direction = -1;
                }
        } else if(direction == -1){
            associated.box.x -= speed;
            if (associated.box.x <=0){
                    direction = 1;
                }
        }
    }
}

void Bixo::Update(float dt){
    Damage(1);
    if (anim->GetCurrentFrame() == 5 || anim->GetCurrentFrame() == 11){
        step_sound->Play(0);
        std::cout<<"passo"<<std::endl;
    };
    
}

void Bixo::Render(){
    //vazio
}