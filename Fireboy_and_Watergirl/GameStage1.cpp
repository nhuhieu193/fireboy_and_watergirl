#include "GameStage1.h"

Fireboy* FireboyPlayer = NULL;
Watergirl* WatergirlPlayer = NULL;

GameStage1* GameStage1::s_Instance = NULL;

GameStage1::GameStage1() {
    FireboyPlayer = new Fireboy(new Properties("fireboy_idle" , 100 , 400 , CHARACTER_WIDTH , CHARACTER_HEIGHT));
    WatergirlPlayer = new Watergirl(new Properties("watergirl_idle" , 30 , 400 , CHARACTER_WIDTH , CHARACTER_HEIGHT));
}

void GameStage1::Update() {
    FireboyPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Up() , EventHandler::GetInstance() -> Right());
    WatergirlPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyW() , EventHandler::GetInstance() -> KeyD());
}

void GameStage1::Render() {
    Texture::GetInstance() -> Draw("background" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
    FireboyPlayer -> Draw(EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Right());
    WatergirlPlayer -> Draw(EventHandler::GetInstance() -> KeyA() , EventHandler::GetInstance() -> KeyD());
    Engine::GetInstance() -> CurrentMap -> Draw();
}
