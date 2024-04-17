#include "Engine.h"
#include "texture.h"
#include "Vector2D.h"
#include "Transform.h"

#include <vector>

#include "BackgroundStage.h"
#include "GameStage1.h"
#include "GameStage2.h"
#include "GameStage3.h"
#include "GameStage4.h"
#include "GameStage5.h"

Engine* Engine::s_Instance = NULL;

void Engine::Events() {
    EventHandler::GetInstance() -> Listen();
}

bool Engine::Init() {
    m_isRunning = true;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Music::GetInstance() -> LoadMUS("BackgroundMusic" , "audio/pianotheme.mp3");
    Music::GetInstance() -> LoadMUS("fireboyandwatergirl" , "audio/fireboyandwatergirl_soundstrack.mp3");
    Music::GetInstance() -> LoadCHU("click" , "audio/click.mp3");
    Music::GetInstance() -> LoadCHU("dead" , "audio/dead.mp3");
    Music::GetInstance() -> LoadCHU("jump" , "audio/jump.mp3");
    Music::GetInstance() -> LoadCHU("levelpassed" , "audio/levelpassed.mp3");

    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
    Music::GetInstance() -> PlayMusic("BackgroundMusic");

    myWindow = SDL_CreateWindow("Fireboy and watergirl" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN);
    myRenderer = SDL_CreateRenderer(myWindow , -1 , SDL_RENDERER_ACCELERATED);

    Texture::GetInstance() -> Load("IntroBackground" , "media/IntroBackground.png");
    Texture::GetInstance() -> Load("PlayTouched" , "media/PlayTouched.png");
    Texture::GetInstance() -> Load("background" , "media/bg.png");

    Texture::GetInstance() -> Load("fireboy_idle" , "media/fireboy_idle.png");
    Texture::GetInstance() -> Load("watergirl_idle" , "media/watergirl_idle.png");
    Texture::GetInstance() -> Load("fireboy_running" , "media/fireboy_running.png");
    Texture::GetInstance() -> Load("watergirl_running" , "media/watergirl_running.png");

    Texture::GetInstance() -> Load("brick" , "media/brick.png");
    Texture::GetInstance() -> Load("door" , "media/Door.png");

    Texture::GetInstance() -> Load("lava" , "media/lava.png");
    Texture::GetInstance() -> Load("water" , "media/water.png");
    Texture::GetInstance() -> Load("greengoo" , "media/greengoo.png");

    Texture::GetInstance() -> Load("smoke" , "media/smoke.png");
    Texture::GetInstance() -> Load("blueSlide" , "media/blueSlide.png");
    Texture::GetInstance() -> Load("blueButton" , "media/blueButton.png");
    Texture::GetInstance() -> Load("greenSlide" , "media/greenSlide.png");
    Texture::GetInstance() -> Load("greenButton" , "media/greenButton.png");
    Texture::GetInstance() -> Load("redSlide" , "media/redSlide.png");
    Texture::GetInstance() -> Load("redButton" , "media/redButton.png");
    Texture::GetInstance() -> Load("yellowSlide" , "media/yellowSlide.png");
    Texture::GetInstance() -> Load("yellowButton" , "media/yellowButton.png");

    Texture::GetInstance() -> Load("pauseButton" , "media/PauseButton.png");

    Texture::GetInstance() -> Load("Paused" , "media/Paused.png");
    Texture::GetInstance() -> Load("PausedResume" , "media/PausedResume.png");
    Texture::GetInstance() -> Load("PausedRetry" , "media/PausedRetry.png");

    Texture::GetInstance() -> Load("GameOver" , "media/GameOver.png");
    Texture::GetInstance() -> Load("GameOverRetry" , "media/GameOverRetry.png");

    Texture::GetInstance() -> Load("LevelPassed" , "media/LevelPassed.png");
    Texture::GetInstance() -> Load("LevelPassedNextLevel" , "media/LevelPassedNextLevel.png");

    Texture::GetInstance() -> Load("youwin" , "media/youwin.png");

    Texture::GetInstance() -> Load("speaker_on" , "media/speaker_on.png");
    Texture::GetInstance() -> Load("speaker_off" , "media/speaker_off.png");
    Texture::GetInstance() -> Load("sound_on" , "media/sound_on.png");
    Texture::GetInstance() -> Load("sound_off" , "media/sound_off.png");

    Texture::GetInstance() -> LoadText("Use arrow keys to move fireboy" , 30 , "fonts/IntroFont.ttf" , {184 , 199 , 36 , 181});
    Texture::GetInstance() -> LoadText("Use A,W,D to move watergirl" , 30 , "fonts/IntroFont.ttf" , {184 , 199 , 36 , 181});
    Texture::GetInstance() -> LoadText("Never mix fire and water !!!" , 30 , "fonts/IntroFont.ttf" , {184 , 199 , 36 , 181});
    Texture::GetInstance() -> LoadText("Green goo hurts them both" , 30 , "fonts/IntroFont.ttf" , {184 , 199 , 36 , 181});
    Texture::GetInstance() -> LoadText("Use buttons" , 30 , "fonts/IntroFont.ttf" , {184 , 199 , 36 , 181});
    Texture::GetInstance() -> LoadText("To control slides" , 30 , "fonts/IntroFont.ttf" , {184 , 199 , 36 , 181});
    Texture::GetInstance() -> LoadText("And combine" , 30 , "fonts/IntroFont.ttf" , {184 , 199 , 36 , 181});
    Texture::GetInstance() -> LoadText("To pass through" , 30 , "fonts/IntroFont.ttf" , {184 , 199 , 36 , 181});
    Texture::GetInstance() -> LoadText("LEVEL 1" , 35 , "fonts/LevelFont.ttf" , {45 , 251 , 0 , 209});
    Texture::GetInstance() -> LoadText("LEVEL 2" , 35 , "fonts/LevelFont.ttf" , {45 , 251 , 0 , 209});
    Texture::GetInstance() -> LoadText("LEVEL 3" , 35 , "fonts/LevelFont.ttf" , {45 , 251 , 0 , 209});
    Texture::GetInstance() -> LoadText("LEVEL 4" , 35 , "fonts/LevelFont.ttf" , {45 , 251 , 0 , 209});
    Texture::GetInstance() -> LoadText("LEVEL 5" , 35 , "fonts/LevelFont.ttf" , {45 , 251 , 0 , 209});

    return true;
}

void Engine::Update() {
    switch (GameStage + 0) {
        case 0: BackgroundStage::GetInstance() -> Update();break;
        case 1: GameStage1::GetInstance() -> Update();break;
        case 2: GameStage2::GetInstance() -> Update();break;
        case 3: GameStage3::GetInstance() -> Update();break;
        case 4: GameStage4::GetInstance() -> Update();break;
        case 5: GameStage5::GetInstance() -> Update();break;
    }
}

void Engine::Render() {
    Timer::GetInstance() -> TimerDelay();
    SDL_SetRenderDrawColor(myRenderer , 0xFF , 0xFF , 0xFF , 0xFF);
    SDL_RenderClear(myRenderer);

    switch (GameStage + 0) {
        case 0: BackgroundStage::GetInstance() -> Implement();break;
        case 1: GameStage1::GetInstance() -> Render();break;
        case 2: GameStage2::GetInstance() -> Render();break;
        case 3: GameStage3::GetInstance() -> Render();break;
        case 4: GameStage4::GetInstance() -> Render();break;
        case 5: GameStage5::GetInstance() -> Render();break;
        case 6:
            Texture::GetInstance() -> Draw("background" , 0 , 0 , SCREEN_WIDTH , SCREEN_HEIGHT);
            Texture::GetInstance() -> Draw("youwin" , 0 , 70 , 900 , 453);
    }
    SDL_RenderPresent(myRenderer);
}

void Engine::Quit() {
    m_isRunning = false;
}

void Engine::Clean() {
    Texture::GetInstance() -> Clean();
    Music::GetInstance() -> Clean();
    SDL_DestroyWindow(myWindow);
    SDL_DestroyRenderer(myRenderer);
    IMG_Quit();
    SDL_Quit();
    Mix_Quit();
    TTF_Quit();
}
