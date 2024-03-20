#include "Player.h"

Player::Player()
    : Entity("Player"), m_X(0.0f), m_Y(0.0f)
{
    FZ_INFO("Entity: {}", PrintEntityName());
}

void Player::CreateEntity()
{
    m_FreezeQuad->CreateQuad(100.0f, 100.0f, "", ""); // TODO: "" -> DEFAULT_SHADERS
    m_FreezeTriangle->CreateTriangle(0.0f, 0.0f, "", "");

    float x = 20.0f;
    float y = 300.0f;
    for(int i = 0; i < 10; i++)
    {
        x += 30.0f;
        y += 40.0f;

        m_PhysicsEntity->CreateDynamicPhysicsBody({ 100.0f, 100.0f }, { x, y }, 1.0f, 0.3f);
    }

}

void Player::MovePlayer(GLFWwindow* window, float dt)
{
    if(Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_D)) // Move Right
    {
        m_X += 500.0f * dt;
    }
    if(Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_A)) // Move Left
    {
        m_X -= 500.0f * dt;
    }
    if(Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_SPACE))
    {
        m_Y += 500.0f * dt;
    }
    if(Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_S))
    {
        m_Y -= 500.0f * dt;
    }
}

void Player::OnImGui()
{
    ImGui::ColorEdit4("Color", playerColors);

    ImGui::Text("X Coord: %f", m_X);
    ImGui::Text("Y Coord: %f", m_Y);
}

void Player::RenderEntity(const glm::mat4& projectionMatrix)
{
    m_PhysicsEntity->RenderPhysicsBody(projectionMatrix, { 0.4f, 0.1f, 0.7f, 1.0f });


    // m_FreezeQuad->RenderQuad(projectionMatrix, { m_X, m_Y }, glm::vec4({playerColors[0], playerColors[1], playerColors[2], playerColors[3]}));
    // m_FreezeTriangle->RenderTriangle(projectionMatrix, { 400.0f, 200.0f }, { 0.2f, 0.6f, 0.9f, 1.0f });
}


Player::~Player()
{
}