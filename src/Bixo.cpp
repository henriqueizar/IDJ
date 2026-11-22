#include "Bixo.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include <iostream>
#include "Animator.h"
#include "InputManager.h"

Bixo::Bixo(GameObject& associated) : Component(associated), hitpoints(100), speed(2.0f){
    SpriteRenderer* sr = new SpriteRenderer(associated, "./assets/img/bixo-Sheet.png", 6, 5);
    associated.AddComponent(sr);
    associated.box.w = 48;
    associated.box.h = 48;
    anim = new Animator(associated);
    anim->AddAnimation("walking",Animation(5,18,2, true));
    anim->AddAnimation("stopped",Animation(0,4,3, true));
    anim->AddAnimation("grabbing",Animation(19,25,2, false));
    associated.AddComponent(anim);
    anim->SetAnimation("stopped");
    step_sound = new Sound("./assets/audio/passo.wav");
}

void Bixo::Grab(/*GameObject& item*/) {
    anim->SetAnimation("grabbing");
    grabbing = true;
    std::cout << anim->IsFinished();



    
    /*if (hitpoints > -300){
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
    }*/
}

void Bixo::Update(float dt){
    
    
    if (InputManager::GetInstance().KeyPress('e') && !grabbing){
        Grab();
    }
    if (grabbing){
        if (anim->IsFinished() == true){
        anim->SetAnimation("stopped");
        grabbing = false;
        }
    }
    if (anim->GetCurrentFrame() == 5 || anim->GetCurrentFrame() == 11){
        step_sound->Play(0);
        std::cout<<"passo"<<std::endl;
    };
    
}

void Bixo::Render(){
    //vazio
}