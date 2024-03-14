#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>

#include "init.h"

#include "character.h"
#include "texture.h"
#include "timer.h"

using namespace std;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

SDL_Window* myWindow = NULL;

SDL_Renderer* myRenderer = NULL;

int main(int argc, char* args[])
{
	Init(myWindow , SCREEN_WIDTH , SCREEN_HEIGHT , myRenderer); /// Create window

	LTexture background;                                        /// Load background
	background.mWidth = SCREEN_WIDTH;
	background.mHeight = SCREEN_HEIGHT;
    background.loadFromFile(myRenderer , "media/background1.png");

    LTimer controlFPStimer;

	bool quit = false;
	SDL_Event event;
	while (!quit) {
        while (SDL_PollEvent(&event)) if (event.type == SDL_QUIT) quit = true;
        controlFPStimer.start();

        background.render(myRenderer , 0 , 0);
//        SDL_SetRenderDrawColor(myRenderer , 0xFF , 0xFF , 0xFF , 0xFF);
//        SDL_RenderClear(myRenderer);



        int TicksCounted = controlFPStimer.getTicks();
        if (TicksCounted < SCREEN_TICKS_PER_FRAME) {
            SDL_Delay(SCREEN_TICKS_PER_FRAME - TicksCounted);
        }

        SDL_RenderPresent(myRenderer);
	}
	return 0;
}



