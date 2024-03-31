#ifndef __GAMESTAGE1__
#define __GAMESTAGE1__

#include "Engine.h"
#include "Fireboy.h"

class GameStage1 {
    static GameStage1* s_Instance;

public:
    GameStage1();
    static GameStage1* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new GameStage1());
    }
    void Update();
    void Render();
};

#endif // __GAMESTAGE1__
