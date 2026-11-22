#ifndef CAMERA_H
#define CAMERA_H
#include "GameObject.h"
#include "Vec2.h"

class Camera{
    public:
        static void Follow(GameObject* focus);
        static void Unfollow();
        static void Update(float dt);
        static Vec2 pos;
        static Vec2 speedVector;
        static void SetWorldSize(int w, int h);

    private:
        static GameObject* focus;
        static Vec2 worldSize;

};

#endif