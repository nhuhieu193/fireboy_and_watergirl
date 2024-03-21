#include "Engine.h"
#include "texture.h"
#include "Vector2D.h"
#include "Transform.h"

#include <vector>

#include "Fireboy.h"
#include "Wall.h"
#include "EventHandler.h"

/// source : consult from Youtube tutorial

const int OBJECT_SIZE = 30;

Engine* Engine::s_Instance = NULL;
Fireboy* FireboyPlayer = NULL;

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

    FireboyPlayer = new Fireboy(new Properties("fireboy" , 100 , 0 , 40 , 66));

    Texture::GetInstance() -> Load("brick" , "stuffmedia/brick.png");

    for (int i = 0 ; i < SCREEN_WIDTH ; i += OBJECT_SIZE) {
        Wall::GetInstance() -> WallList.push_back(new Wall(new Properties("brick" , i , SCREEN_HEIGHT - OBJECT_SIZE , OBJECT_SIZE , OBJECT_SIZE)));
    }

    return true;
}

void Engine::Update() {
    FireboyPlayer -> Update(0.05);
//    Texture::GetInstance() -> Draw("brick" , 300 , 300 , 30 , 30);
    for (auto e : Wall::GetInstance() -> WallList) {
        e -> Draw();
    }
}

void Engine::Render() {

//    Texture::GetInstance() -> Draw("background" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
//    Texture::GetInstance() -> Draw("fireboy" , 200 , 300 , 40 , 66);

//    SDL_SetRenderDrawColor(myRenderer , 0xFF , 0xFF , 0xFF , 0xFF);
//    SDL_RenderClear(myRenderer);

    FireboyPlayer -> Draw();

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
