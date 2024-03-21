#ifndef __PROPERTIES__
#define __PROPERTIES__

#include "Transform.h"
#include <SDL.h>
#include <iostream>
#include "texture.h"

struct Properties {
    Properties(std::string textureID , double x , double y , int width , int height , SDL_RendererFlip flip = SDL_FLIP_NONE) {
        X = x;
        Y = y;
        Flip = flip;
        Width = width;
        Height = height;
        TextureID = textureID;
    }

    std::string TextureID;
    int Width , Height;
    double X,Y;
    SDL_RendererFlip Flip;
};

#endif // __PROPERTIES__
