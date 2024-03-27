#include "Fireboy.h"
#include "texture.h"
void Fireboy::Draw() {
    Texture::GetInstance() -> Draw(m_TextureID , m_Transform->X , m_Transform->Y , m_Width , m_Height);
}

void Fireboy::Update(double dt , bool Left , bool Up , bool Right) {
    if (Left == 1) m_RigidBody -> m_Velocity.X = -200;else
    if (Right == 1) m_RigidBody -> m_Velocity.X = 200;else m_RigidBody -> m_Velocity.X = 0;
    if (Up == 1 && m_Transform -> Y == SCREEN_HEIGHT - 89) m_RigidBody -> m_Velocity.Y = -300;

    m_RigidBody -> Update(dt);
    m_Transform -> Translate(m_RigidBody -> Position());
    if (m_Transform -> Y > SCREEN_HEIGHT - OBJECT_SIZE - 59) m_Transform -> Y = SCREEN_HEIGHT - OBJECT_SIZE - 59;
}
