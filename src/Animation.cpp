#include "Animation.h"

Animation::Animation(int frameStart, int frameEnd, float frameTime){
    this->frameEnd = frameEnd;
    this->frameStart = frameStart;
    this->frameTime = frameTime;
}