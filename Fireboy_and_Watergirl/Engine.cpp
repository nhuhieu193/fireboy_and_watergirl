#include "Engine.h"
#include "texture.h"
#include "Vector2D.h"
#include "Transform.h"

#include <vector>

#include "Fireboy.h"
#include "EventHandler.h"

#include "Timer.h"
#include "Map.h"

/// source : consult from Youtube tutorial

Engine* Engine::s_Instance = NULL;
Fireboy* FireboyPlayer = NULL;

Map* Introduction = NULL;

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
    Texture::GetInstance() -> Load("fireboy" , "media/fireboy.png");

    FireboyPlayer = new Fireboy(new Properties("fireboy" , 100 , 400 , 29 , 59));


    Texture::GetInstance() -> Load("wall" , "stuffmedia/brick.png");

    Introduction = new Map("maplevel/introduction.txt");

    return true;
}

void Engine::Update() {
    FireboyPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Up() , EventHandler::GetInstance() -> Right());
}

void Engine::Render() {
    Timer::GetInstance() -> TimerDelay();
    SDL_SetRenderDrawColor(myRenderer , 0xFF , 0xFF , 0xFF , 0xFF);
    SDL_RenderClear(myRenderer);

    FireboyPlayer -> Draw();

    Introduction -> Draw();
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
