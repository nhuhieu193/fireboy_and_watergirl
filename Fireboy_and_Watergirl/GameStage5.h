#ifndef __GAMESTAGE5__
#define __GAMESTAGE5__

#include "Engine.h"
#include "Fireboy.h"
#include "Watergirl.h"
#include "FireboyDoor.h"
#include "WatergirlDoor.h"

#include "Menu.h"

class GameStage5 {
    static GameStage5* s_Instance;
    Fireboy* FireboyPlayer = NULL;
    Watergirl* WatergirlPlayer = NULL;
    FireboyDoor* fireboyDoor = NULL;
    WatergirlDoor* watergirlDoor = NULL;

    const int FIREBOY_INITIAL_POSITION_X = 25;
    const int FIREBOY_INITIAL_POSITION_Y = 480;
    const int WATERGIRL_INITIAL_POSITION_X = 80;
    const int WATERGIRL_INITIAL_POSITION_Y = 480;

    const int FIREBOY_DOOR_POSITION_X = 710;
    const int FIREBOY_DOOR_POSITION_Y = 40;
    const int WATERGIRL_DOOR_POSITION_X = 810;
    const int WATERGIRL_DOOR_POSITION_Y = 40;

    int StageOver = 0;
    int StageOverCountTicks = 0;
    int SmokeFrames = 12;
    int SmokeAnimationSpeed = 10;
    int CoordinateSmokeX , CoordinateSmokeY;

    void UpdateStageOver();

    Menu* Option;

public:
    GameStage5();
    static GameStage5* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new GameStage5());
    }

    void Update();
    void Render();
};

#endif // __GAMESTAGE2__
