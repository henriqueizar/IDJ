#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL
#include "SDL_include.h"
//#include "State.h"
#include <string>



class Game{
    
private:
Game(std::string title, int width, int height);
    
    ~Game();
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
   /** State* state;*/



public:
    static Game& GetInstance(std::string title, int width, int height);
    void Run();
    SDL_Renderer* GetRenderer();
    //State& GetState();
};


#endif
