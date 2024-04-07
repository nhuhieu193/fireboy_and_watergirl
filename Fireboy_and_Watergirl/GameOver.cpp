#include "GameOver.h"
#include "texture.h"

GameOver* GameOver::s_Instance = NULL;

GameOver::GameOver() {
    Play = new SDL_Rect;
    Play -> x = 331;
    Play -> y = 325;
    Play -> w = 184;
    Play -> h = 82;
}

void GameOver::Implement() {
    Texture::GetInstance() -> Draw("IntroBackground" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    if (PlayTouched()) {
        Texture::GetInstance() -> Draw("PlayTouched" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    }
    if (PlayClicked()) {
        Engine::GetInstance() -> GameStage++;
    }
}

bool GameOver::PlayTouched() {
    stateMouse = SDL_GetMouseState(&x , &y);
    if (x >= Play -> x && x <= Play -> x + Play -> w && y >= Play -> y && y <= Play -> y + Play -> h) return true;
    return false;
}

bool GameOver::PlayClicked() {
    stateMouse = SDL_GetMouseState(&x , &y);
    if (PlayTouched() && stateMouse == 1) return true;
    return false;
}
