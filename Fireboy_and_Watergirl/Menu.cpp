#include "Menu.h"

Menu* Menu::s_Instance = NULL;

Menu::Menu() {
    MenuMask = 0;
    numFrames = FPS * MenuTime / 1000;
    currentFrames = 0;
    Velocity = 1.0 * 510 / numFrames;

    ButtonInMenu PausedMenu;
    PausedMenu.Resume = {280 , 306 , 151 , 51};
    PausedMenu.Retry = {483 , 306 , 142 , 51};
    MenuList.push_back(PausedMenu);

    ButtonInMenu NextLevel;
    NextLevel.NextLevel = {322 , 283 , 224 , 51};
    MenuList.push_back(NextLevel);

    ButtonInMenu GameOver;
    GameOver.Retry = {371 , 330 , 142 , 51};
    MenuList.push_back(GameOver);
}

void Menu::Update() {

}

void Menu::Draw() {
    Texture::GetInstance() -> Draw("pauseButton" , SCREEN_WIDTH - 50 , 0 , 50 , 50);
    if (recentMenuMask == 1) {
        string state = "Paused";
        if (IsMenuScreenCompletelyShown()) {
            if (MenuList[GAME_PAUSED].IsTouched(MenuList[GAME_PAUSED].Resume)) state += "Resume";else
            if (MenuList[GAME_PAUSED].IsTouched(MenuList[GAME_PAUSED].Retry)) state += "Retry";
        }
        Texture::GetInstance() -> Draw(state , 90 , SCREEN_HEIGHT - Velocity * currentFrames , MENUWIDTH , MENUHEIGHT);
    }else if (recentMenuMask == 2) {
        string state = "LevelPassed";
        if (IsMenuScreenCompletelyShown()) {
            if (MenuList[GAME_LEVELPASSED].IsTouched(MenuList[GAME_LEVELPASSED].NextLevel)) state += "NextLevel";
        }
        Texture::GetInstance() -> Draw(state , 90 , SCREEN_HEIGHT - Velocity * currentFrames , MENUWIDTH , MENUHEIGHT);
    }else if (recentMenuMask == 3) {
        string state = "GameOver";
        if (IsMenuScreenCompletelyShown()) {
            if (MenuList[GAME_GAMEOVER].IsTouched(MenuList[GAME_GAMEOVER].Retry)) state += "Retry";
        }
        Texture::GetInstance() -> Draw(state , 90 , SCREEN_HEIGHT - Velocity * currentFrames , MENUWIDTH , MENUHEIGHT);
    }

}

void Menu::UpdateShowingMenu() {
    if (MenuMask) currentFrames++;else currentFrames--;
    if (currentFrames > numFrames) currentFrames = numFrames;
    if (currentFrames < 0) currentFrames = 0;
    if (currentFrames == 0) recentMenuMask = 0;
}

bool Menu::PauseButtonIsClicked() {
    int x,y;
    int MouseType = SDL_GetMouseState(&x , &y);
    if (x >= SCREEN_WIDTH - 50 && y <= 50 && MouseType == 1 && x <= SCREEN_WIDTH && y >= 0) return true;
    return false;
}

bool Menu::IsMenuScreenCompletelyShown() {
    if (currentFrames == numFrames || currentFrames == 0) return true;
    return false;
}

void Menu::SetMask(int u) {
    MenuMask = u;
    recentMenuMask = u;
}
