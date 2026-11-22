#include "Camera.h"
#include "Game.h"
#include "InputManager.h"
#include <iostream>

constexpr int CAM_SPEED_PX_PER_SEC = 2;
GameObject* Camera::focus = nullptr;
Vec2 Camera::pos = Vec2(0,0);
Vec2 Camera::speedVector = Vec2(0,0);
Vec2 Camera::worldSize = Vec2(0,0);

void Camera::Follow(GameObject* focus){
    Camera::focus = focus;
}
void Camera::Unfollow(){
    Camera::focus = nullptr;
}
void Camera::Update(float dt){
    Vec2 direction = Vec2(0,0);
    if (focus != nullptr){
        pos.x = (focus->box.x) - (Game::LOGICAL_WIDTH)/2;
        pos.y = (focus->box.y) - (Game::LOGICAL_HEIGHT)/2;
    } else{
        if (InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY)){
            direction = direction.operator+(Vec2(-1,0));
        } 
        if (InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY)){
            direction = direction.operator+(Vec2(1,0));    
        }
        if (InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY)){
            direction = direction.operator+(Vec2(0,-1));
        }
        if (InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY)){
            direction = direction.operator+(Vec2(0,1));
        }
        
        speedVector = direction*CAM_SPEED_PX_PER_SEC;
        pos = pos.operator+(speedVector);
        if (pos.x <= 0){
            pos.x = 0;
        }
        if (pos.x >= worldSize.x - Game::LOGICAL_WIDTH){
            pos.x = worldSize.x - Game::LOGICAL_WIDTH;
        }
        if (pos.y <= 0){
            pos.y = 0;
        }
        if (pos.y >= worldSize.y - Game::LOGICAL_HEIGHT){
            pos.y = worldSize.y - Game::LOGICAL_HEIGHT;
        }
    }
}

void Camera::SetWorldSize(int w, int h){
    worldSize = Vec2(w,h);
}