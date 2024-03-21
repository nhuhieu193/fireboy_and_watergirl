#include "Fireboy.h"
#include "texture.h"
#include "Wall.h"

void Fireboy::Draw() {
    Texture::GetInstance() -> Draw(m_TextureID , m_Transform->X , m_Transform->Y , m_Width , m_Height);
}

void Fireboy::Update(double dt) {
    m_RigidBody -> Update(dt);
    m_RigidBody -> ApplyForceX(0.02);
    m_Transform -> TranslateX(m_RigidBody -> Position().X);
    m_Transform -> TranslateY(m_RigidBody -> Position().Y);
    if (CollideWithWall()) {
        m_Transform -> TranslateX(- m_RigidBody -> Position().X);
        m_Transform -> TranslateY(- m_RigidBody -> Position().Y);
    }
}

bool Fireboy::CollideWithASingleWall(Wall* tmp) {
    double l = m_Transform -> X , r = l + m_Width , u = tmp -> m_Transform -> X , v = u + tmp -> m_Width;
    if (l > v || r < u) return false;
    l = m_Transform -> Y; r = l + m_Height; u = tmp -> m_Transform -> Y; v = u + tmp -> m_Height;
    if (l > v || r < u) return false;
    return true;
}

bool Fireboy::CollideWithWall() {
    for (int i = 0 ; i < (int)Wall::GetInstance() -> WallList.size() ; i++) {
        if (CollideWithASingleWall(Wall::GetInstance() -> WallList[i])) return true;
    }
    return false;
}
