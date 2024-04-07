#ifndef __TEXTURE__
#define __TEXTURE__

/// source : consult from Youtube tutorial

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>
#include "Engine.h"

class Texture {
    Texture(){};
    static Texture* s_Instance;

    std::map<std::string , SDL_Texture*> m_TextureMap;

public:
    static Texture* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new Texture());
    }

    bool Load(std::string id , std::string filename);
    void Clean();

    void Draw(std::string id , int x , int y , int width , int height , SDL_RendererFlip flip = SDL_FLIP_NONE);
    void DrawFrame(std::string id , int x , int y , int subX , int subY , int frame , SDL_RendererFlip flip = SDL_FLIP_NONE);
    void DrawDoor(std::string id , int x , int y , int width , int height , int row , int frame);
    void DrawLiquid(std::string id , int x , int y , int width , int height , int frame);
};

#endif // __TEXTURE__
