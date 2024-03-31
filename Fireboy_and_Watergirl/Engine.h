#ifndef __ENGINE__
#define __ENGINE__

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "EventHandler.h"
#include "Timer.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const int OBJECT_SIZE = 30;
const int CHARACTER_WIDTH = 40;
const int CHARACTER_HEIGHT = 61;


#include "Map.h"

class Engine {
    Engine(){};
    bool m_isRunning;
    static Engine* s_Instance;

    SDL_Window* myWindow = NULL;
    SDL_Renderer* myRenderer = NULL;

public:
    Map* CurrentMap = NULL;
    int GameStage = 0;

    static Engine* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new Engine());
    }

    void Events();
    bool Init();
    void Update();
    void Quit();
    void Clean();
    void Render();

    inline SDL_Renderer* GetRenderer() {
        return myRenderer;
    }

    inline bool isRunning() {
        return m_isRunning;
    }
};

#endif // __ENGINE__
