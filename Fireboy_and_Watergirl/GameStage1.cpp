#include "GameStage1.h"

GameStage1* GameStage1::s_Instance = NULL;

GameStage1::GameStage1() {
    Engine::GetInstance() -> CurrentMap = new Map("1");
    FireboyPlayer = new Fireboy(new Properties("fireboy_idle" , FIREBOY_INITIAL_POSITION_X , FIREBOY_INITIAL_POSITION_Y , CHARACTER_WIDTH , CHARACTER_HEIGHT));
    WatergirlPlayer = new Watergirl(new Properties("watergirl_idle" , WATERGIRL_INITIAL_POSITION_X , WATERGIRL_INITIAL_POSITION_Y , CHARACTER_WIDTH , CHARACTER_HEIGHT));

    fireboyDoor = new FireboyDoor(800 , 40);
    watergirlDoor = new WatergirlDoor(700 , 40);

    Option = Menu::GetInstance();
}

void GameStage1::Update() {
    if (Option->MenuMask == 0 && Option ->IsMenuScreenCompletelyShown() && Option ->PauseButtonIsClicked()) Option->SetMask(1);
    Option->UpdateShowingMenu();
    if (Option->MenuMask == 1) {
        if (Option->MenuList[GAME_PAUSED].IsClicked(Option->MenuList[GAME_PAUSED].Resume)) {
            Option->MenuMask = 0;
        }else if (Option->MenuList[GAME_PAUSED].IsClicked(Option->MenuList[GAME_PAUSED].Retry)) {
            StageOver = 0;
            FireboyPlayer -> m_Transform -> X = FIREBOY_INITIAL_POSITION_X; FireboyPlayer -> m_Transform -> Y = FIREBOY_INITIAL_POSITION_Y;
            WatergirlPlayer -> m_Transform -> X = WATERGIRL_INITIAL_POSITION_X; WatergirlPlayer -> m_Transform -> Y = WATERGIRL_INITIAL_POSITION_Y;
            Option->MenuMask = 0;
            StageOverCountTicks = 0;
            return;
        }else return;
    }
    UpdateStageOver();
    if (fireboyDoor -> GameCompleted() && watergirlDoor -> GameCompleted()) Option -> SetMask(2);
    if (StageOver) {
        if (StageOverCountTicks == SmokeFrames * SmokeAnimationSpeed) {
            Option -> SetMask(3);
        }else StageOverCountTicks++;
    }
    if (Option->MenuMask == 3) {
        if (Option->MenuList[GAME_GAMEOVER].IsClicked(Option->MenuList[GAME_GAMEOVER].Retry)) {
            StageOver = 0;
            FireboyPlayer -> m_Transform -> X = 640; FireboyPlayer -> m_Transform -> Y = 500;
            WatergirlPlayer -> m_Transform -> X = 250; WatergirlPlayer -> m_Transform -> Y = 500;
            Option->MenuMask = 0;
            StageOverCountTicks = 0;
        }
        return;
    }
    if (Option->MenuMask == 2) {
        if (Option->MenuList[GAME_LEVELPASSED].IsClicked(Option->MenuList[GAME_LEVELPASSED].NextLevel)) {
            Engine::GetInstance() -> GameStage++;
            Option->MenuMask = 0;
        }
        return;
    }
    if (StageOver) return;
    FireboyPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Up() , EventHandler::GetInstance() -> Right());
    WatergirlPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyW() , EventHandler::GetInstance() -> KeyD());
    fireboyDoor -> Update(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT);
    watergirlDoor -> Update(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT);
}

void GameStage1::Render() {
    Texture::GetInstance() -> Draw("background" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    Engine::GetInstance() -> CurrentMap -> Draw();
    fireboyDoor -> Render();
    watergirlDoor -> Render();
    FireboyPlayer -> Draw(EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Right());
    WatergirlPlayer -> Draw(EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyD());
    Menu::GetInstance() -> Draw();
}

void GameStage1::UpdateStageOver() {
    if (Engine::GetInstance() -> CurrentMap -> CollideWithLava(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT)) {
        StageOver = 1;
        CoordinateSmokeX = WatergirlPlayer -> m_Transform -> X;
        CoordinateSmokeY = WatergirlPlayer -> m_Transform -> Y;
        return;
    }
    if (Engine::GetInstance() -> CurrentMap -> CollideWithWater(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT)) {
        StageOver = 2;
        CoordinateSmokeX = FireboyPlayer -> m_Transform -> X;
        CoordinateSmokeY = FireboyPlayer -> m_Transform -> Y;
        return;
    }
    if (Engine::GetInstance() -> CurrentMap -> CollideWithGreenGoo(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT)) {
        StageOver = 1;
        CoordinateSmokeX = WatergirlPlayer -> m_Transform -> X;
        CoordinateSmokeY = WatergirlPlayer -> m_Transform -> Y;
        return;
    }
    if (Engine::GetInstance() -> CurrentMap -> CollideWithGreenGoo(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT)) {
        StageOver = 2;
        CoordinateSmokeX = FireboyPlayer -> m_Transform -> X;
        CoordinateSmokeY = FireboyPlayer -> m_Transform -> Y;
        return;
    }
}

