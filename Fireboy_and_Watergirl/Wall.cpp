#include "Wall.h"
#include "texture.h"

Wall* Wall::s_Instance = NULL;

void Wall::Draw() {
    Texture::GetInstance() ->Draw(m_TextureID , m_Transform -> X , m_Transform -> Y , m_Width , m_Height);
}
