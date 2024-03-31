#include "Engine.h"
#include "texture.h"
#include "Vector2D.h"
#include "Transform.h"

#include <vector>

#include "BackgroundStage.h"
#include "GameStage1.h"

Engine* Engine::s_Instance = NULL;

void Engine::Events() {
    EventHandler::GetInstance() -> Listen();
}

bool Engine::Init() {
    m_isRunning = true;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    myWindow = SDL_CreateWindow("Fireboy and watergirl" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN);
    myRenderer = SDL_CreateRenderer(myWindow , -1 , SDL_RENDERER_ACCELERATED);

    Texture::GetInstance() -> Load("background" , "media/background1.png");
    Texture::GetInstance() -> Load("fireboy" , "media/fireboy_animation.png");
    Texture::GetInstance() -> Load("running" , "media/running_animation.png");

    Texture::GetInstance() -> Load("wall" , "stuffmedia/brick.png");

    Engine::GetInstance() -> CurrentMap = new Map("maplevel/introduction.txt");

    return true;
}

void Engine::Update() {
    switch (GameStage) {
        case 1: GameStage1::GetInstance() -> Update();
    }
//    FireboyPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Up() , EventHandler::GetInstance() -> Right());
}

void Engine::Render() {
    Timer::GetInstance() -> TimerDelay();
    SDL_SetRenderDrawColor(myRenderer , 0xFF , 0xFF , 0xFF , 0xFF);
    SDL_RenderClear(myRenderer);

    switch (GameStage) {
        case 0: BackgroundStage::GetInstance() -> Implement();break;
        case 1: GameStage1::GetInstance() -> Render();break;
    }
    SDL_RenderPresent(myRenderer);
}

void Engine::Quit() {
    m_isRunning = false;
}

void Engine::Clean() {
    Texture::GetInstance() -> Clean();
    SDL_DestroyWindow(myWindow);
    SDL_DestroyRenderer(myRenderer);
    IMG_Quit();
    SDL_Quit();
}
