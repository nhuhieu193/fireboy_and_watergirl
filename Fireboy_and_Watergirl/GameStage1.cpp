#include "GameStage1.h"

GameStage1* GameStage1::s_Instance = NULL;

GameStage1::GameStage1() {
    Engine::GetInstance() -> CurrentMap = new Map("1");
    FireboyPlayer = new Fireboy(new Properties("fireboy_idle" , 100 , 400 , CHARACTER_WIDTH , CHARACTER_HEIGHT));
    WatergirlPlayer = new Watergirl(new Properties("watergirl_idle" , 30 , 400 , CHARACTER_WIDTH , CHARACTER_HEIGHT));

    fireboyDoor = new FireboyDoor(800 , 40);
    watergirlDoor = new WatergirlDoor(700 , 40);
}

void GameStage1::Update() {
    FireboyPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Up() , EventHandler::GetInstance() -> Right());
    WatergirlPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyW() , EventHandler::GetInstance() -> KeyD());
    fireboyDoor -> Update(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT);
    watergirlDoor -> Update(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT);
    if (fireboyDoor -> GameCompleted() && watergirlDoor -> GameCompleted()) Engine::GetInstance() -> GameStage++;
}

void GameStage1::Render() {
    Texture::GetInstance() -> Draw("background" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    Engine::GetInstance() -> CurrentMap -> Draw();
    fireboyDoor -> Render();
    watergirlDoor -> Render();
    FireboyPlayer -> Draw(EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Right());
    WatergirlPlayer -> Draw(EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyD());

}
