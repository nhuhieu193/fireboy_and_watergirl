#ifndef __FIREBOY__
#define __FIREBOY__

#include "GameObject.h"
#include "RigidBody.h"

class Fireboy : public GameObject {
public:
    Fireboy(Properties* props);

    virtual void Draw();
    virtual void Update(double dt);
    virtual void Clean();

    RigidBody* m_RigidBody;
};

#endif // __FIREBOY__
