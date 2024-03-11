#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>

using namespace std;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;

void Init(); /// Initialize
SDL_Texture* getTextureFromFile(SDL_Renderer* renderer , const char* path);

SDL_Window* myWindow = NULL;

SDL_Renderer* myRenderer = NULL;

SDL_Texture* background = NULL;
void getBackground();

int main( int argc, char* args[])
{
	Init();
    getBackground();

	bool quit = false;
	SDL_Event event;
	while (!quit) {
        while (SDL_PollEvent(&event)) if (event.type == SDL_QUIT) quit = true;

        SDL_SetRenderDrawColor(myRenderer , 0xFF , 0xFF , 0xFF , 0xFF);
        SDL_RenderClear(myRenderer);

        SDL_RenderCopy(myRenderer , background , NULL , NULL);

        SDL_RenderPresent(myRenderer);
	}


	return 0;
}

void getBackground() {
    background = getTextureFromFile(myRenderer , "media/background.png");
}

SDL_Texture* getTextureFromFile(SDL_Renderer* renderer , const char* filePath) {
    SDL_Surface* surface = IMG_Load(filePath);
    SDL_Texture* LoadedTexture = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);
    return LoadedTexture;
}

void Init() {
    SDL_Init(SDL_INIT_VIDEO);
    myWindow = SDL_CreateWindow("Fireboy and watergirl" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN);

    myRenderer = SDL_CreateRenderer(myWindow , -1 , SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(myRenderer , 0xFF , 0xFF , 0xFF , 0xFF);
}
