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

#include <iostream>

void Timer::TimerDelay() {
    UpdateCurTime();
    Uint64 elapsedTime = curTime - preTime;
    if (elapsedTime < frameDuration) {
//        std::cout << frequency << '\n';
//        std::cout << (frameDuration - elapsedTime) * 1000 / frequency << '\n';
        SDL_Delay((frameDuration - elapsedTime) * 1000 / frequency);
    }
    UpdatePreTime();
}
