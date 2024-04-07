#ifndef __GAMEOVER__
#define __GAMEOVER__

#include "Engine.h"

class GameOver {
    static GameOver* s_Instance;
    SDL_Rect* Play;
    int x,y;
    int stateMouse;
    int cnt = 0;
public:
    GameOver();
    static GameOver* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new GameOver());
    }
    void Implement();
    bool PlayClicked();
    bool PlayTouched();
};

#endif // __GAMEOVER__
