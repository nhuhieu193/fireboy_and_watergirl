#include "BackgroundStage.h"
#include "texture.h"

BackgroundStage* BackgroundStage::s_Instance = NULL;

BackgroundStage::BackgroundStage() {
    Play = new SDL_Rect;
    Play -> y = 350;
    Play -> h = 100;
    Play -> x = 300;
    Play -> w = 300;
}

void BackgroundStage::Implement() {
    Texture::GetInstance() -> Draw("background" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    if (PlayClicked()) {
        Engine::GetInstance() -> GameStage++;
    }
}

bool BackgroundStage::PlayClicked() {
    stateMouse = SDL_GetMouseState(&x , &y);
    if (x >= Play -> x && x <= Play -> x + Play -> w && y >= Play -> y && y <= Play -> y + Play -> h && stateMouse == 1) return true;
    return false;
}
