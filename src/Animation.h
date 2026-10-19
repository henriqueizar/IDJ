#ifndef ANIMATION_H
#define ANIMATION_H


class Animation{
    public:
        Animation(int frameStart, int frameEnd, float frameTime);
        int frameStart;
        int frameEnd;
        float frameTime;
};

#endif