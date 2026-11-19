#ifndef TIMER_H
#define TIMER_H

class Timer{
    private:
        float time;

    public:
        Timer();
        void Update(float dt);
        void Restart();
        float Get();
};

#endif