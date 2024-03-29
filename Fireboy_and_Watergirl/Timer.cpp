#include "Timer.h"

Timer* Timer::s_Instance = NULL;

Timer::Timer(){
    frequency = SDL_GetPerformanceFrequency();
    frameDuration = frequency / FPS;
    UpdatePreTime();
}

void Timer::UpdatePreTime() {
    preTime = SDL_GetPerformanceCounter();
}

void Timer::UpdateCurTime() {
    curTime = SDL_GetPerformanceCounter();
}

void Timer::TimerDelay() {
    UpdateCurTime();
    Uint64 elapsedTime = curTime - preTime;
    if (elapsedTime < frameDuration) {
        SDL_Delay((frameDuration - elapsedTime) * 1000 / frequency);
    }
    UpdatePreTime();
}
