#ifndef ANIMATION_H
#define ANIMATION_H


class Animation{
    public:
        Animation(int frameStart, int frameEnd, float frameTime, bool loop);
        int frameStart;
        int frameEnd;
        float frameTime;
        bool loop = true;
};

#endif