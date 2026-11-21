#include "Animation.h"

Animation::Animation(int frameStart, int frameEnd, float frameTime, bool loop){
    this->frameEnd = frameEnd;
    this->frameStart = frameStart;
    this->frameTime = frameTime;
    this->loop = loop;
}