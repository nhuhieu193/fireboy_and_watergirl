#include "BackgroundStage.h"
#include "texture.h"

BackgroundStage* BackgroundStage::s_Instance = NULL;

BackgroundStage::BackgroundStage() {
    Play = new SDL_Rect;
    Play -> x = 331;
    Play -> y = 325;
    Play -> w = 184;
    Play -> h = 82;
}

void BackgroundStage::Implement() {
    Texture::GetInstance() -> Draw("IntroBackground" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    if (PlayTouched()) {
        Texture::GetInstance() -> Draw("PlayTouched" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    }
    if (PlayClicked()) {
        Music::GetInstance() -> PlayChunk("click");
        Engine::GetInstance() -> GameStage++;
    }
}

bool BackgroundStage::PlayTouched() {
    stateMouse = SDL_GetMouseState(&x , &y);
    if (x >= Play -> x && x <= Play -> x + Play -> w && y >= Play -> y && y <= Play -> y + Play -> h) return true;
    return false;
}

bool BackgroundStage::PlayClicked() {
    stateMouse = SDL_GetMouseState(&x , &y);
    if (PlayTouched() && stateMouse == 1) return true;
    return false;
}
