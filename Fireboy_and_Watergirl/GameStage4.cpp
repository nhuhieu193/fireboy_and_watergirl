#include "GameStage4.h"

GameStage4* GameStage4::s_Instance = NULL;

GameStage4::GameStage4() {
    Engine::GetInstance() -> CurrentMap = new Map("4");
    FireboyPlayer = new Fireboy(new Properties("fireboy_idle" , FIREBOY_INITIAL_POSITION_X , FIREBOY_INITIAL_POSITION_Y , CHARACTER_WIDTH , CHARACTER_HEIGHT));
    WatergirlPlayer = new Watergirl(new Properties("watergirl_idle" , WATERGIRL_INITIAL_POSITION_X , WATERGIRL_INITIAL_POSITION_Y , CHARACTER_WIDTH , CHARACTER_HEIGHT));

    fireboyDoor = new FireboyDoor(FIREBOY_DOOR_POSITION_X , FIREBOY_DOOR_POSITION_Y);
    watergirlDoor = new WatergirlDoor(WATERGIRL_DOOR_POSITION_X , WATERGIRL_DOOR_POSITION_Y);

    Option = Menu::GetInstance();
}

void GameStage4::Update() {
    Music::GetInstance() -> Update();
    if (HandleMenu()) return;
    if (StageOver) return;
    FireboyPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Up() , EventHandler::GetInstance() -> Right());
    WatergirlPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyW() , EventHandler::GetInstance() -> KeyD());
    fireboyDoor -> Update(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT);
    watergirlDoor -> Update(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT);
    Engine::GetInstance() -> CurrentMap -> Update(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y);
}

void GameStage4::Render() {
    Texture::GetInstance() -> Draw("background" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    Texture::GetInstance() -> DrawText("LEVEL 4" , 360 , 0);
    fireboyDoor -> Render(); watergirlDoor -> Render();
    if (StageOver) Texture::GetInstance() -> DrawSmoke(CoordinateSmokeX , CoordinateSmokeY , StageOverCountTicks / SmokeAnimationSpeed);
    if (StageOver != 2) FireboyPlayer -> Draw(EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Right());
    if (StageOver != 1) WatergirlPlayer -> Draw(EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyD());
    Engine::GetInstance() -> CurrentMap -> Draw();
    Music::GetInstance() -> Draw();
    Menu::GetInstance() -> Draw();
}

bool GameStage4::HandleMenu() {
    if (Option->MenuMask == 0 && Option ->IsMenuScreenCompletelyShown() && Option ->PauseButtonIsClicked()) {
        Music::GetInstance() -> PlayChunk("click");
        Option->SetMask(1);
    }
    Option->UpdateShowingMenu();
    if (Option->MenuMask == 1) {
        if (Option->MenuList[GAME_PAUSED].IsClicked(Option->MenuList[GAME_PAUSED].Resume)) {
            Music::GetInstance() -> PlayChunk("click");
            Option->MenuMask = 0;
        }else if (Option->MenuList[GAME_PAUSED].IsClicked(Option->MenuList[GAME_PAUSED].Retry)) {
            Music::GetInstance() -> PlayChunk("click");
            StageOver = 0;
            FireboyPlayer -> m_Transform -> X = FIREBOY_INITIAL_POSITION_X; FireboyPlayer -> m_Transform -> Y = FIREBOY_INITIAL_POSITION_Y;
            WatergirlPlayer -> m_Transform -> X = WATERGIRL_INITIAL_POSITION_X; WatergirlPlayer -> m_Transform -> Y = WATERGIRL_INITIAL_POSITION_Y;
            Option->MenuMask = 0;
            StageOverCountTicks = 0;
            return true;
        }else return true;
    }
    UpdateStageOver();
    if (Option->MenuMask == 0 && fireboyDoor -> GameCompleted() && watergirlDoor -> GameCompleted()) {
        Music::GetInstance() -> PlayChunk("levelpassed");
        Option -> SetMask(2);
    }
    if (Option->MenuMask == 2) {
        if (Option->MenuList[GAME_LEVELPASSED].IsClicked(Option->MenuList[GAME_LEVELPASSED].NextLevel)) {
            Music::GetInstance() -> PlayChunk("click");
            delete Engine::GetInstance() -> CurrentMap;
            Engine::GetInstance() -> GameStage++;
            Option->MenuMask = 0;
        }
        return true;
    }
    if (StageOver) {
        if (StageOverCountTicks == SmokeFrames * SmokeAnimationSpeed) {
            Option -> SetMask(3);
        }else StageOverCountTicks++;
    }
    if (Option->MenuMask == 3) {
        if (Option->MenuList[GAME_GAMEOVER].IsClicked(Option->MenuList[GAME_GAMEOVER].Retry)) {
            Music::GetInstance() -> PlayChunk("click");
            StageOver = 0;
            FireboyPlayer -> m_Transform -> X = FIREBOY_INITIAL_POSITION_X; FireboyPlayer -> m_Transform -> Y = FIREBOY_INITIAL_POSITION_Y;
            WatergirlPlayer -> m_Transform -> X = WATERGIRL_INITIAL_POSITION_X; WatergirlPlayer -> m_Transform -> Y = WATERGIRL_INITIAL_POSITION_Y;
            Option->MenuMask = 0;
            StageOverCountTicks = 0;
        }
        return true;
    }
    return false;
}

void GameStage4::UpdateStageOver() {
    if (StageOver) return;
    if (Engine::GetInstance() -> CurrentMap -> CollideWithLava(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT)) {
        StageOver = 1;
        CoordinateSmokeX = WatergirlPlayer -> m_Transform -> X;
        CoordinateSmokeY = WatergirlPlayer -> m_Transform -> Y;
        Music::GetInstance() -> PlayChunk("dead");
        return;
    }
    if (Engine::GetInstance() -> CurrentMap -> CollideWithWater(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT)) {
        StageOver = 2;
        CoordinateSmokeX = FireboyPlayer -> m_Transform -> X;
        CoordinateSmokeY = FireboyPlayer -> m_Transform -> Y;
        Music::GetInstance() -> PlayChunk("dead");
        return;
    }
    if (Engine::GetInstance() -> CurrentMap -> CollideWithGreenGoo(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT)) {
        StageOver = 1;
        CoordinateSmokeX = WatergirlPlayer -> m_Transform -> X;
        CoordinateSmokeY = WatergirlPlayer -> m_Transform -> Y;
        Music::GetInstance() -> PlayChunk("dead");
        return;
    }
    if (Engine::GetInstance() -> CurrentMap -> CollideWithGreenGoo(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT)) {
        StageOver = 2;
        CoordinateSmokeX = FireboyPlayer -> m_Transform -> X;
        CoordinateSmokeY = FireboyPlayer -> m_Transform -> Y;
        Music::GetInstance() -> PlayChunk("dead");
        return;
    }
}
