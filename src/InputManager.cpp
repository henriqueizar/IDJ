#include "InputManager.h"

#include "SDL_include.h"

InputManager::InputManager() : mouseState{}, mouseUpdate{}, updateCounter(0), quitRequested(false), mouseX(0), mouseY(0){

}

// O construtor deve inicializar os arrays de estado e update do mouse.
// Se você estiver usando vetores para as teclas, faça o mesmo para eles. Já as
// tabelas de hash não precisam (nem devem) ser inicializadas. Lembre-se
// também das outras variáveis da classe (updateCounter, quitRequested e
// mouse)


InputManager::~InputManager(){
}


void InputManager::Update() {
    SDL_Event event;

    SDL_GetMouseState(&mouseX, &mouseY);
    quitRequested = false;
    updateCounter++;

    while (SDL_PollEvent(&event)) {   //switch case em event type        
        switch (event.type) {             
        case SDL_QUIT:
            quitRequested = true;
            break;

        case SDL_MOUSEBUTTONDOWN:
            mouseState[event.button.button]  = true;
            mouseUpdate[event.button.button] = updateCounter;
            break;

        case SDL_MOUSEBUTTONUP:
            mouseState[event.button.button]  = false;
            mouseUpdate[event.button.button] = updateCounter;
            break;

        case SDL_KEYDOWN:
            if (event.key.repeat) break;     // ignore auto-repeat
            keyState[event.key.keysym.sym]  = true;
            keyUpdate[event.key.keysym.sym] = updateCounter;
            break;

        case SDL_KEYUP:
            keyState[event.key.keysym.sym]  = false;
            keyUpdate[event.key.keysym.sym] = updateCounter;
            break;
        }
    }
}

bool InputManager::IsMouseDown(int button)    { return mouseState[button]; }
bool InputManager::MousePress(int button)     { return  mouseState[button] && mouseUpdate[button] == updateCounter; }//isso será chamado por classes que precisam consultar se o mouse foi clicado
bool InputManager::MouseRelease(int button)   { return !mouseState[button] && mouseUpdate[button] == updateCounter; }

bool InputManager::KeyPress(int key){
    return keyState[key] && keyUpdate[key] == updateCounter;
}

bool InputManager::KeyRelease(int key){
    return !keyState[key] && keyUpdate[key] == updateCounter;
}

bool InputManager::IsKeyDown(int key){
    return keyState[key];
}

int InputManager::GetMouseX(){
    return mouseX;
}

int InputManager::GetMouseY(){
    return mouseY;
}

InputManager& InputManager::GetInstance(){
    static InputManager inputManager;
    return inputManager;
}