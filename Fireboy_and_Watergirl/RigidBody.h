#ifndef __RIGIDBODY__
#define __RIGIDBODY__

#define GRAVITY 700.0f

#include <iostream>
#include "Vector2D.h"

class RigidBody {
public:
    Vector2D m_Velocity;
    double m_Mass, m_Gravity;
    Vector2D m_Position;
    Vector2D m_Acceleration;

    RigidBody() {
        m_Gravity = GRAVITY;
        m_Velocity = Vector2D(0 , 0);
    }

    inline Vector2D Position() {return m_Position;}
    void Update(double dt) {
        m_Acceleration.Y = m_Gravity;
        m_Velocity.Y = m_Velocity.Y + m_Acceleration.Y * dt;
        m_Position = m_Velocity * dt;
    }

    void ResetVelocity() {
        m_Velocity = Vector2D(0 , 0);
    }
};

#endif // __RIGIDBODY__
