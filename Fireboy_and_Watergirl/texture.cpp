#include "texture.h"
#include "Engine.h"

/// source : consult from Youtube tutorial

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

void Texture::Drop(std::string id){
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}

void Texture::Clean() {
    for (std::map<std::string , SDL_Texture*>::iterator it = m_TextureMap.begin(); it != m_TextureMap.end() ; it++)
        SDL_DestroyTexture(it -> second);
    m_TextureMap.clear();
}
