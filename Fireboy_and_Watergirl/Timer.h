#ifndef __TIMER__
#define __TIMER__

#include <SDL.h>

const int FPS = 60;

class Timer {
    Uint64 preTime , curTime;
    Uint64 frequency , frameDuration;
    static Timer* s_Instance;
public:
    Timer();
    static Timer* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new Timer());
    }

    void UpdatePreTime();
    void UpdateCurTime();
    void TimerDelay();
};

#endif // __TIMER__
