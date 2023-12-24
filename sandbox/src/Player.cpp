#include "Player.h"

Player::Player()
    : Entity("Player"), m_X(0.0f), m_Y(0.0f)
{
    FZ_INFO("Entity: {}", PrintEntityName());
}

void Player::CreateEntity()
{
    m_Renderer2D->CreateQuad(100.0f, 100.0f);
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

void Player::OnImGui()
{
    ImGui::Begin("Edit Entity:");
    ImGui::ColorEdit4("Color", playerColors);

    ImGui::Text("X Coord: %f", m_X);
    ImGui::Text("Y Coord: %f", m_Y);

    ImGui::End();
}

void Player::RenderEntity(const glm::mat4& projectionMatrix)
{
    m_Renderer2D->DrawQuad(projectionMatrix, { m_X, m_Y }, glm::vec4({playerColors[0], playerColors[1], playerColors[2], playerColors[3]}));
    m_Renderer2D->DrawQuad(projectionMatrix, { 130.0f, 170.0f }, { 0.3f, 0.2f, 0.1f, 1.0f });
}

Player::~Player()
{
}
