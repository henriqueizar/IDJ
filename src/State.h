#ifndef STATE_H
#define STATE_H
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"
#include <string>
#include "GameObject.h"


class State{
    public:
        State();
        ~State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
        void AddObject(GameObject* go);

    private:
        /*GameObject* bg;
        GameObject* bixo;*/
        Music music;
        bool quitRequested;
        std::vector<std::unique_ptr<GameObject>> objectArray;
};

#endif