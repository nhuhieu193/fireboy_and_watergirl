#ifndef __BACKGROUNDSTAGE__
#define __BACKGROUNDSTAGE__

#include "Engine.h"

class BackgroundStage {
    static BackgroundStage* s_Instance;
    SDL_Rect* Play;
    int x,y;
    int stateMouse;
    int cnt = 0;
public:
    BackgroundStage();
    static BackgroundStage* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new BackgroundStage());
    }
    void Update();
    void Implement();
    bool PlayClicked();
    bool PlayTouched();
};

#endif // __BACKGROUNDSTAGE__
