#ifndef __GAMESTAGE2__
#define __GAMESTAGE2__

#include "Engine.h"
#include "Fireboy.h"
#include "Watergirl.h"
#include "FireboyDoor.h"
#include "WatergirlDoor.h"

class GameStage2 {
    static GameStage2* s_Instance;
    Fireboy* FireboyPlayer = NULL;
    Watergirl* WatergirlPlayer = NULL;
    FireboyDoor* fireboyDoor = NULL;
    WatergirlDoor* watergirlDoor = NULL;
public:
    GameStage2();
    static GameStage2* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new GameStage2());
    }
    void Update();
    void Render();
};

#endif // __GAMESTAGE2__
