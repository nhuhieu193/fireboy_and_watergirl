#ifndef __GAMESTAGE3__
#define __GAMESTAGE3__

#include "Engine.h"
#include "Fireboy.h"
#include "Watergirl.h"
#include "FireboyDoor.h"
#include "WatergirlDoor.h"

#include "Menu.h"

class GameStage3 {
    static GameStage3* s_Instance;
    Fireboy* FireboyPlayer = NULL;
    Watergirl* WatergirlPlayer = NULL;
    FireboyDoor* fireboyDoor = NULL;
    WatergirlDoor* watergirlDoor = NULL;

    const int FIREBOY_INITIAL_POSITION_X = 640;
    const int FIREBOY_INITIAL_POSITION_Y = 500;
    const int WATERGIRL_INITIAL_POSITION_X = 250;
    const int WATERGIRL_INITIAL_POSITION_Y = 500;

    const int FIREBOY_DOOR_POSITION_X = 120;
    const int FIREBOY_DOOR_POSITION_Y = 400;
    const int WATERGIRL_DOOR_POSITION_X = 725;
    const int WATERGIRL_DOOR_POSITION_Y = 400;

    int StageOver = 0;
    int StageOverCountTicks = 0;
    int SmokeFrames = 12;
    int SmokeAnimationSpeed = 10;
    int CoordinateSmokeX , CoordinateSmokeY;

    void UpdateStageOver();
    bool HandleMenu();

    Menu* Option;

public:
    GameStage3();
    static GameStage3* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new GameStage3());
    }

    void Update();
    void Render();
};

#endif // __GAMESTAGE2__

