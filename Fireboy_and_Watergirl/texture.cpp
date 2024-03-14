#include "texture.h"

/// source : lazyfoo

LTexture::LTexture() {
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture() {
    freeTexture();
}

void LTexture::freeTexture() {
    if (mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::setColor(Uint8 red , Uint8 green , Uint8 blue) {
    SDL_SetTextureColorMod(mTexture , red , green , blue);
}

void LTexture::setBlendMode(SDL_BlendMode blendmode) {
    SDL_SetTextureBlendMode(mTexture , blendmode);
}

void LTexture::setAlpha(Uint8 alpha) {
    SDL_SetTextureAlphaMod(mTexture , alpha);
}

void LTexture::render(SDL_Renderer*& myRenderer, int x , int y , SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_Rect renderQuad = {x , y , mWidth , mHeight};
    if (clip != NULL) {
        renderQuad.w = clip -> w;
        renderQuad.h = clip -> h;
    }
    SDL_RenderCopyEx(myRenderer , mTexture , clip , &renderQuad , angle , center , flip);
}

bool LTexture::loadFromFile(SDL_Renderer*& myRenderer, std::string path) {
    freeTexture();
    SDL_Surface* surface = IMG_Load(path.c_str());
    SDL_Texture* LoadedTexture = SDL_CreateTextureFromSurface(myRenderer , surface);
    SDL_FreeSurface(surface);
    mTexture = LoadedTexture;
    return mTexture != NULL;
}
