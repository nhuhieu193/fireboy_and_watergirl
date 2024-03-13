#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>

#include "init_and_background.h"

using namespace std;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;

SDL_Window* myWindow = NULL;

SDL_Renderer* myRenderer = NULL;

SDL_Texture* background = NULL;

int main(int argc, char* args[])
{
	Init(myWindow , SCREEN_WIDTH , SCREEN_HEIGHT , myRenderer);
    getBackground(background , myRenderer);

	bool quit = false;
	SDL_Event event;
	while (!quit) {
        while (SDL_PollEvent(&event)) if (event.type == SDL_QUIT) quit = true;

        SDL_RenderCopy(myRenderer , background , NULL , NULL);

        SDL_RenderPresent(myRenderer);
	}
	return 0;
}



