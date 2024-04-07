#include "texture.h"
#include "Engine.h"

Texture* Texture::s_Instance = NULL;

bool Texture::Load(std::string id , std::string filename) {
    SDL_Surface* surface = IMG_Load(filename.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance() -> GetRenderer() , surface);
    SDL_FreeSurface(surface);
    m_TextureMap[id] = texture;
    return true;
}

void Texture::Draw(std::string id , int x , int y , int width , int height , SDL_RendererFlip flip) {
    SDL_Rect srcRect = {0 , 0 , width , height};
    SDL_Rect dstRect = {x , y , width , height};
    SDL_RenderCopyEx(Engine::GetInstance() -> GetRenderer() , m_TextureMap[id] , &srcRect , &dstRect , 0 , NULL , flip);
}

void Texture::DrawFrame(std::string id , int x , int y , int subX , int subY , int frame , SDL_RendererFlip flip) {
    SDL_Rect srcRect = {0 + frame * 100, 0 , 100 , 100};
    SDL_Rect dstRect = {x - subX, y - subY, 100 , 100};
    SDL_RenderCopyEx(Engine::GetInstance() -> GetRenderer() , m_TextureMap[id] , &srcRect , &dstRect , 0 , NULL , flip);
}

void Texture::DrawDoor(std::string id , int x , int y , int width , int height , int row , int frame) {
    SDL_Rect srcRect = {frame * width , row * height , width , height};
    SDL_Rect dstRect = {x , y , width , height};
    SDL_RenderCopyEx(Engine::GetInstance() -> GetRenderer() , m_TextureMap[id] , &srcRect , &dstRect , 0 , NULL , SDL_FLIP_NONE);
}

void Texture::DrawLiquid(std::string id , int x , int y , int width , int height , int frame) {
    SDL_Rect srcRect = {frame * 6 , 0 , width , height};
    SDL_Rect dstRect = {x , y , width , height};
    SDL_RenderCopyEx(Engine::GetInstance() -> GetRenderer() , m_TextureMap[id] , &srcRect , &dstRect , 0 , NULL , SDL_FLIP_NONE);
}

void Texture::DrawSmoke(int x , int y , int frame) {
    DrawFrame("smoke" , x , y , 30 , 29 , frame , SDL_FLIP_NONE);
}

void Texture::Clean() {
    for (std::map<std::string , SDL_Texture*>::iterator it = m_TextureMap.begin(); it != m_TextureMap.end() ; it++)
        SDL_DestroyTexture(it -> second);
    m_TextureMap.clear();
}
