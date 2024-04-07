#ifndef __GAMESTAGE1__
#define __GAMESTAGE1__

#include "Engine.h"
#include "Fireboy.h"
#include "Watergirl.h"
#include "FireboyDoor.h"
#include "WatergirlDoor.h"

class GameStage1 {
    static GameStage1* s_Instance;
    Fireboy* FireboyPlayer = NULL;
    Watergirl* WatergirlPlayer = NULL;
    FireboyDoor* fireboyDoor = NULL;
    WatergirlDoor* watergirlDoor = NULL;
public:
    GameStage1();
    static GameStage1* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new GameStage1());
    }
    void Update();
    void Render();
};

#endif // __GAMESTAGE1__