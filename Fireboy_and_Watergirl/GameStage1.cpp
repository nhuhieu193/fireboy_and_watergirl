#include "GameStage1.h"

Fireboy* FireboyPlayer = NULL;

GameStage1* GameStage1::s_Instance = NULL;

GameStage1::GameStage1() {
    FireboyPlayer = new Fireboy(new Properties("fireboy" , 100 , 400 , CHARACTER_WIDTH , CHARACTER_HEIGHT));
}

void GameStage1::Update() {
    FireboyPlayer -> Update(1.0 / FPS , EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Up() , EventHandler::GetInstance() -> Right());
}

void GameStage1::Render() {
    FireboyPlayer -> Draw(EventHandler::GetInstance() -> Left() , EventHandler::GetInstance() -> Right());

    Engine::GetInstance() -> CurrentMap -> Draw();
}
