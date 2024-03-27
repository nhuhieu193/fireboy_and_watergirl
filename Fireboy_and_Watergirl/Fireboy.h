#ifndef __FIREBOY__
#define __FIREBOY__

#include "RigidBody.h"
#include "Properties.h"

class Fireboy{
    std::string m_TextureID;
    SDL_RendererFlip m_Flip;
public:
    int m_Width, m_Height;
    Transform* m_Transform;

    Fireboy(Properties* props) : m_TextureID(props -> TextureID) ,
        m_Width(props -> Width) , m_Height(props -> Height) , m_Flip(props -> Flip) {
        m_Transform = new Transform(props -> X , props -> Y);
        m_RigidBody = new RigidBody();
    }

    void Draw();
    void Update(double dt, bool Left , bool Up , bool Right);

    RigidBody* m_RigidBody;
};

#endif // __FIREBOY__
