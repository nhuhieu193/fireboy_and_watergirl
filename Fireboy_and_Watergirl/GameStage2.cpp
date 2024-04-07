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
    FireboyPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Up() , EventHandler::GetInstance() -> Right());
    WatergirlPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyW() , EventHandler::GetInstance() -> KeyD());
//    fireboyDoor -> Update(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT);
//    watergirlDoor -> Update(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT);
    if (Engine::GetInstance() -> CurrentMap -> CollideWithLava(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT))
        Engine::GetInstance() -> GameStage++;
    if (Engine::GetInstance() -> CurrentMap -> CollideWithWater(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT))
        Engine::GetInstance() -> GameStage++;
    if (Engine::GetInstance() -> CurrentMap -> CollideWithGreenGoo(WatergirlPlayer -> m_Transform -> X , WatergirlPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT))
        Engine::GetInstance() -> GameStage++;
    if (Engine::GetInstance() -> CurrentMap -> CollideWithGreenGoo(FireboyPlayer -> m_Transform -> X , FireboyPlayer -> m_Transform -> Y , CHARACTER_WIDTH , CHARACTER_HEIGHT))
        Engine::GetInstance() -> GameStage++;
}

void GameStage2::Render() {
    Texture::GetInstance() -> Draw("background" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    Engine::GetInstance() -> CurrentMap -> Draw();
//    fireboyDoor -> Render();
//    watergirlDoor -> Render();
//    Texture::GetInstance() -> Draw("lava" , 510 , 540 , 90 , 30);
    FireboyPlayer -> Draw(EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Right());
    WatergirlPlayer -> Draw(EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyD());

}

