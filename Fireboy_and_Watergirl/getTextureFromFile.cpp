#include <SDL.h>
#include <SDL_image.h>

SDL_Texture* getTextureFromFile(SDL_Renderer*& renderer , const char* filePath) {
    SDL_Surface* surface = IMG_Load(filePath);
    SDL_Texture* LoadedTexture = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);
    return LoadedTexture;
}
