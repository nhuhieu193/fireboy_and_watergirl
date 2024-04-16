#ifndef __GAMESTAGE1__
#define __GAMESTAGE1__

#include "Engine.h"
#include "Fireboy.h"
#include "Watergirl.h"
#include "FireboyDoor.h"
#include "WatergirlDoor.h"

#include "Menu.h"

class GameStage1 {
    static GameStage1* s_Instance;
    Fireboy* FireboyPlayer = NULL;
    Watergirl* WatergirlPlayer = NULL;
    FireboyDoor* fireboyDoor = NULL;
    WatergirlDoor* watergirlDoor = NULL;

    const int FIREBOY_INITIAL_POSITION_X = 100;
    const int FIREBOY_INITIAL_POSITION_Y = 400;
    const int WATERGIRL_INITIAL_POSITION_X = 30;
    const int WATERGIRL_INITIAL_POSITION_Y = 400;

    const int FIREBOY_DOOR_POSITION_X = 800;
    const int FIREBOY_DOOR_POSITION_Y = 40;
    const int WATERGIRL_DOOR_POSITION_X = 700;
    const int WATERGIRL_DOOR_POSITION_Y = 40;

    int StageOver = 0;
    int StageOverCountTicks = 0;
    int SmokeFrames = 12;
    int SmokeAnimationSpeed = 10;
    int CoordinateSmokeX , CoordinateSmokeY;

    void UpdateStageOver();
    bool HandleMenu();

    Menu* Option;

public:
    GameStage1();
    static GameStage1* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new GameStage1());
    }

    void Update();
    void Render();
};

#endif // __GAMESTAGE1__
