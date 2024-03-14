#ifndef __TEXTURE__
#define __TEXTURE__

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

/// source : lazyfoo

class LTexture {
public:
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;

    LTexture();

    ~LTexture();

    bool loadFromFile(SDL_Renderer*& , std::string path);

    void freeTexture();

    void setColor(Uint8 red , Uint8 green , Uint8 blue);

    void setBlendMode(SDL_BlendMode blendmode);

    void setAlpha(Uint8 alpha);

    void render(SDL_Renderer*& ,int x , int y , SDL_Rect* clip = NULL , double angle = 0.0 , SDL_Point* center = NULL , SDL_RendererFlip flip = SDL_FLIP_NONE);

};

#endif // __TEXTURE__
