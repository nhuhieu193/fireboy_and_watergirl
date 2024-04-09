#include "GameStage2.h"

GameStage2* GameStage2::s_Instance = NULL;

GameStage2::GameStage2() {
    Engine::GetInstance() -> CurrentMap = new Map("2");
    FireboyPlayer = new Fireboy(new Properties("fireboy_idle" , 100 , 400 , CHARACTER_WIDTH , CHARACTER_HEIGHT));
    WatergirlPlayer = new Watergirl(new Properties("watergirl_idle" , 30 , 400 , CHARACTER_WIDTH , CHARACTER_HEIGHT));

//    fireboyDoor = new FireboyDoor(800 , 40);
//    watergirlDoor = new WatergirlDoor(700 , 40);
}

void GameStage2::Update() {
    if (StageOver) {
        if (StageOverCountTicks == SmokeFrames * SmokeAnimationSpeed) Engine::GetInstance() -> GameStage++;
        StageOverCountTicks++;
        return;
    }
    FireboyPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Up() , EventHandler::GetInstance() -> Right());
    WatergirlPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyW() , EventHandler::GetInstance() -> KeyD());
//    fireboyDoor -> Update(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT);
//    watergirlDoor -> Update(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT);
    Engine::GetInstance() -> CurrentMap -> Update(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y);
    UpdateStageOver();
}

void GameStage2::Render() {
    Texture::GetInstance() -> Draw("background" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
//    Texture::GetInstance() -> Draw("blueSlide" , 100 , 555 , 90 , 15);
//    Texture::GetInstance() -> Draw("blueButton" , 200 , 560 , 29 , 10);
//    fireboyDoor -> Render();
//    watergirlDoor -> Render();
    if (StageOver) Texture::GetInstance() -> DrawSmoke(CoordinateSmokeX , CoordinateSmokeY , StageOverCountTicks / SmokeAnimationSpeed);
    if (StageOver != 2) FireboyPlayer -> Draw(EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Right());
    if (StageOver != 1) WatergirlPlayer -> Draw(EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyD());
    Engine::GetInstance() -> CurrentMap -> Draw();
}

void GameStage2::UpdateStageOver() {
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
