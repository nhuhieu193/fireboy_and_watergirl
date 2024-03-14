#include <SDL.h>
#include <SDL_image.h>

void Init(SDL_Window*& myWindow, const int& SCREEN_WIDTH , const int& SCREEN_HEIGHT , SDL_Renderer*& myRenderer) {
    SDL_Init(SDL_INIT_VIDEO);
    myWindow = SDL_CreateWindow("Fireboy and watergirl" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN);

    myRenderer = SDL_CreateRenderer(myWindow , -1 , SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(myRenderer , 0xFF , 0xFF , 0xFF , 0xFF);
}

