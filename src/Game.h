#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL
#include "SDL_include.h"
//#include "State.h" nao precisa, só fazer forward declaration
#include <string>   

class State; //forward declaration

class Game{
    
private:
Game(std::string title, int width, int height);
    
    ~Game();
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;
    int frameStart;
    float dt;
    void CalculateDeltaTime();
    

public:
    static Game& GetInstance();
    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    float GetDeltaTime();
    static constexpr int LOGICAL_HEIGHT = 180;
    static constexpr int LOGICAL_WIDTH = 320;

};


#endif
