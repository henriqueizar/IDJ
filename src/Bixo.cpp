#include "Bixo.h"
#include "SpriteRenderer.h"
#include "GameObject.h"

#include "Animator.h"

Bixo::Bixo(GameObject& associated) : Component(associated), hitpoints(100), speed(2.0f){
    SpriteRenderer* sr = new SpriteRenderer(associated, "./assets/img/bixo_andando-Sheet.png", 4, 4);
    associated.AddComponent(sr);
    Animator* anim = new Animator(associated);
    anim->AddAnimation("walking",Animation(0,13,2));
    associated.AddComponent(anim);
    anim->SetAnimation("walking");
}

void Bixo::Damage(int damage){
    hitpoints -= damage;
    if (hitpoints > 0){
        SpriteRenderer* sr = associated.GetComponent<SpriteRenderer>();
        //sr -> SetFrame(10);
        associated.box.x += speed;
    }
}

void Bixo::Update(float dt){
    Damage(1);
}

void Bixo::Render(){
    //vazio
}