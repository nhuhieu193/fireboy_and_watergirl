#ifndef __FIREBOY__
#define __FIREBOY__

#include "RigidBody.h"
#include "Properties.h"
class Fireboy{
    std::string m_TextureID;
    SDL_RendererFlip m_Flip;

    int numFrame;
    int AnimationSpeed;
    int subX,subY;

    std::string TextureRunning;
public:
    int m_Width, m_Height;
    Transform* m_Transform;
    RigidBody* m_RigidBody;

    Fireboy(Properties* props) : m_TextureID(props -> TextureID) ,
        m_Width(props -> Width) , m_Height(props -> Height) , m_Flip(props -> Flip) {
        m_Transform = new Transform(props -> X , props -> Y);
        m_RigidBody = new RigidBody();
        numFrame = 4;
        AnimationSpeed = 100;
        subX = 30;
        subY = 29;
        TextureRunning = "running";
    }

    void Update(double dt, bool Left , bool Up , bool Right);
    void Draw(bool Left , bool Right);
};

#endif // __FIREBOY__
