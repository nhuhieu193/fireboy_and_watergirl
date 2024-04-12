#ifndef __GAMESTAGE4__
#define __GAMESTAGE4__

#include "Engine.h"
#include "Fireboy.h"
#include "Watergirl.h"
#include "FireboyDoor.h"
#include "WatergirlDoor.h"

#include "Menu.h"

class GameStage4 {
    static GameStage4* s_Instance;
    Fireboy* FireboyPlayer = NULL;
    Watergirl* WatergirlPlayer = NULL;
    FireboyDoor* fireboyDoor = NULL;
    WatergirlDoor* watergirlDoor = NULL;

    const int FIREBOY_INITIAL_POSITION_X = 810;
    const int FIREBOY_INITIAL_POSITION_Y = 10;
    const int WATERGIRL_INITIAL_POSITION_X = 30;
    const int WATERGIRL_INITIAL_POSITION_Y = 10;

    const int FIREBOY_DOOR_POSITION_X = 585;
    const int FIREBOY_DOOR_POSITION_Y = 490;
    const int WATERGIRL_DOOR_POSITION_X = 812;
    const int WATERGIRL_DOOR_POSITION_Y = 430;

    int StageOver = 0;
    int StageOverCountTicks = 0;
    int SmokeFrames = 12;
    int SmokeAnimationSpeed = 10;
    int CoordinateSmokeX , CoordinateSmokeY;

    void UpdateStageOver();

    Menu* Option;

public:
    GameStage4();
    static GameStage4* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new GameStage4());
    }

    void Update();
    void Render();
};

#endif // __GAMESTAGE2__
