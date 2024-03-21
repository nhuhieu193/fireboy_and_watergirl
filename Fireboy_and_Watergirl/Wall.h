#ifndef __WALL__
#define __WALL__

#include "Properties.h"
#include <vector>

class Wall{
    std::string m_TextureID;
    SDL_RendererFlip m_Flip;

    static Wall* s_Instance;
    Wall(){};

public:
    int m_Width, m_Height;
    Transform* m_Transform;

    static Wall* GetInstance() {
        return s_Instance = (s_Instance != NULL ? s_Instance : new Wall());
    }

    Wall(Properties* props) : m_TextureID(props -> TextureID) ,
        m_Width(props -> Width) , m_Height(props -> Height) , m_Flip(props -> Flip) {
        m_Transform = new Transform(props -> X , props -> Y);
    }

    void Draw();
    std::vector <Wall*> WallList;
};

#endif // __WALL__
