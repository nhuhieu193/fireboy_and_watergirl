#ifndef __RIGIDBODY__
#define __RIGIDBODY__

#define GRAVITY 0.01f
#define MASS_UNIT 1.0f

#include "Vector2D.h"

class RigidBody {
public:
    RigidBody() {
        m_Mass = MASS_UNIT;
        m_Gravity = GRAVITY;
        m_Velocity = Vector2D(0 , 0);
    }

    inline void SetMass(double mass) {m_Mass = mass;}
    inline void SetGravity(double gravity) {m_Gravity = gravity;}

    inline void ApplyForce(Vector2D F) {m_Force = F;}
    inline void ApplyForceX(double Fx) {m_Force.X = Fx;}
    inline void ApplyForceY(double Fy) {m_Force.Y = Fy;}
    inline void UnSetForce() {m_Force = Vector2D(0 , 0);}

    inline void ApplyFriction(Vector2D Fr) {m_Friction = Fr;}
    inline void UnSetFriction() {m_Friction = Vector2D(0 , 0);}

    inline double GetMass() {return m_Mass;};
    inline Vector2D Velocity() {return m_Velocity;}
    inline Vector2D Position() {return m_Position;}
    inline Vector2D Acceleration() {return m_Acceleration;}

    void Update(double dt) {
        m_Acceleration.X = (m_Force.X + m_Friction.X) / m_Mass;
        m_Acceleration.Y = m_Gravity + m_Force.Y / m_Mass;
        m_Velocity = m_Velocity + m_Acceleration * dt;
        m_Position = m_Velocity * dt;
    }

private:
    double m_Mass, m_Gravity;

    Vector2D m_Force;
    Vector2D m_Friction;

    Vector2D m_Position;
    Vector2D m_Velocity;
    Vector2D m_Acceleration;

};

#endif // __RIGIDBODY__
