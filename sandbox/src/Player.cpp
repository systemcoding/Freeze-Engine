#include "Player.h"

Player::Player() : Entity("Player"), m_X(0.0f), m_Y(0.0f) {
  FZ_INFO("Entity: {}", PrintEntityName());
  m_PhysicsEntity = std::make_shared<Freeze::Physics::DynamicBody>();
  m_PhysicsEntity1 = std::make_shared<Freeze::Physics::DynamicBody>();
}

void Player::CreateEntity() {
  ///////////// 2D BODY (NOT BOX2D) ////////////////////
  // m_FreezeQuad->CreateQuad(440.0f, 300.0f, "", ""); // TODO: "" -> // DEFAULT_SHADERS
  /////////////////////////////////////////////////////

  ////////// BOX2D QUAD //////////////////

  float x = 0.0f;
  float y = 20.0f;

  m_PhysicsEntity->CreateDynamicBody({10.0f, 10.0f}, {x, y}, 1.0f, 0.3f,
                                            0.5f);
  m_PhysicsEntity->CreateDynamicBody(
      {10.0f, 10.0f}, {x + 4.0f, y + 3.0f}, 1.0f, 0.3f, 0.6f);
}

void Player::MovePlayer(GLFWwindow* window, float dt) {
  if (Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_D))  // Move Right
  {
    m_X += 500.0f * dt;
  }
  if (Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_A))  // Move Left
  {
    m_X -= 500.0f * dt;
  }
  if (Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_SPACE)) {
    m_Y += 500.0f * dt;
  }
  if (Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_S)) {
    m_Y -= 500.0f * dt;
  }
}

void Player::OnImGui() {
  ImGui::ColorEdit4("Color", playerColors);

  ImGui::Text("X Coord: %f", m_X);
  ImGui::Text("Y Coord: %f", m_Y);
}

void Player::RenderEntity(const glm::mat4& projectionMatrix) {
  m_PhysicsEntity->RenderDynamicBody(projectionMatrix,
                                     {0.4f, 0.1f, 0.7f, 1.0f});
}

Player::~Player() {}
