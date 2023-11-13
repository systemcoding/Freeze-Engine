#include "Player.h"

Player::Player()
    : Entity("Player"), m_X(0.0f), m_Y(0.0f)
{
    FZ_INFO("Entity: {}", PrintEntityName());
}

void Player::CreateEntity()
{
    m_Renderer2D->CreateQuad();
}

void Player::MovePlayer(GLFWwindow* window)
{
    if(Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_D)) // Move Right
    {
        m_X += 20.0f;
    }
    if(Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_A)) // Move Left
    {
        m_X += -20.0f;
    }
}

void Player::RenderEntity(const glm::mat4& projectionMatrix)
{
    m_Renderer2D->DrawQuad(projectionMatrix);
}

Player::~Player()
{
}
