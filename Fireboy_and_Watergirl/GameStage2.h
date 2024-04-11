#ifndef __GAMESTAGE2__
#define __GAMESTAGE2__

#include "Engine.h"
#include "Fireboy.h"
#include "Watergirl.h"
#include "FireboyDoor.h"
#include "WatergirlDoor.h"

#include "Menu.h"

class GameStage2 {
    static GameStage2* s_Instance;
    Fireboy* FireboyPlayer = NULL;
    Watergirl* WatergirlPlayer = NULL;
    FireboyDoor* fireboyDoor = NULL;
    WatergirlDoor* watergirlDoor = NULL;

    const int FIREBOY_INITIAL_POSITION_X = 50;
    const int FIREBOY_INITIAL_POSITION_Y = 350;
    const int WATERGIRL_INITIAL_POSITION_X = 50;
    const int WATERGIRL_INITIAL_POSITION_Y = 500;

    int StageOver = 0;
    int StageOverCountTicks = 0;
    int SmokeFrames = 12;
    int SmokeAnimationSpeed = 10;
    int CoordinateSmokeX , CoordinateSmokeY;

    void UpdateStageOver();

    Menu* Option;

public:
    GameStage2();
    static GameStage2* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new GameStage2());
    }
    void Update();
    void Render();
};

#endif // __GAMESTAGE2__
