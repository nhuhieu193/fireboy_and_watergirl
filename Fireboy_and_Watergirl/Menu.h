#ifndef __MENU__
#define __MENU__

#include "Engine.h"
#include "texture.h"

const int MENUWIDTH = 720;
const int MENUHEIGHT = 420;
const int MenuTime = 400;

enum {
    GAME_PAUSED,
    GAME_LEVELPASSED,
    GAME_GAMEOVER
};

struct ButtonInMenu {
    SDL_Rect Resume;
    SDL_Rect Retry;
    SDL_Rect NextLevel;

    bool IsTouched(const SDL_Rect& R) {
        int x,y;
        SDL_GetMouseState(&x , &y);
        if (x >= R.x && x <= R.x + R.w && y >= R.y && y <= R.y + R.h) return true;
        return false;
    }
    bool IsClicked(const SDL_Rect& R) {
        int x,y;
        int state = SDL_GetMouseState(&x , &y);
        if (x >= R.x && x <= R.x + R.w && y >= R.y && y <= R.y + R.h && state == 1) return true;
        return false;
    }

};

class Menu {
    static Menu* s_Instance;
    Menu();
    int numFrames;
    int currentFrames;
    double Velocity;

public:
    static Menu* GetInstance() {
        return s_Instance = s_Instance != NULL ? s_Instance : new Menu();
    }
    int MenuMask;
    vector <ButtonInMenu> MenuList;

    int recentMenuMask;
    bool PauseButtonIsClicked();
    bool IsMenuScreenCompletelyShown();
    void SetMask(int u);

    void UpdateShowingMenu();
    void Update();
    void Draw();
};

#endif // __MENU__
