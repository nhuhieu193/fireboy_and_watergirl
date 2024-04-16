#include "Watergirl.h"
#include "texture.h"

void Watergirl::Update(double dt , bool Left , bool Up , bool Right) {
    if (Left == 1) m_RigidBody -> m_Velocity.X = -200;else
    if (Right == 1) m_RigidBody -> m_Velocity.X = 200;else m_RigidBody -> m_Velocity.X = 0;
    if (Up == 1 && Engine::GetInstance() -> CurrentMap -> OnGround(Vector2D(m_Transform -> X , m_Transform -> Y))) {
        Music::GetInstance() -> PlayChunk("jump");
        m_RigidBody -> m_Velocity.Y = -350;
    }

    m_RigidBody -> Update(dt);
    if (m_Transform -> MoveInMap(m_RigidBody -> Position())) m_RigidBody -> ResetVelocity();
}

void Watergirl::Draw(bool Left , bool Right) {
    int Frame = (SDL_GetTicks() / AnimationSpeed) % numFrame;
    if (Left || Right) {
        SDL_RendererFlip flip = (Left ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
        Texture::GetInstance() -> DrawFrame(TextureRunning , m_Transform->X , m_Transform->Y , subX , subY , Frame , flip);
    }else Texture::GetInstance() -> DrawFrame(m_TextureID , m_Transform->X , m_Transform->Y , subX , subY , Frame);
}

