#include "Fireboy.h"
#include "texture.h"

Fireboy::Fireboy(Properties* props) : GameObject(props) {
    m_RigidBody = new RigidBody();
}

void Fireboy::Draw() {
    Texture::GetInstance() -> Draw(m_TextureID , m_Transform->X , m_Transform->Y , m_Width , m_Height);
}

void Fireboy::Update(double dt) {
    m_RigidBody -> Update(dt);
    m_RigidBody -> ApplyForceX(0.02);
    m_Transform -> TranslateX(m_RigidBody -> Position().X);
    m_Transform -> TranslateY(m_RigidBody -> Position().Y);
}

void Fireboy::Clean() {

}
