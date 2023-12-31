#include "World.h"

World::World()
    : m_Camera(std::make_shared<Freeze::Camera>(
          glm::vec4(0.0f, 960.0f, 0.0f, 540.0f)))
                    // left,   right,  bottom,  top
{}

void World::Init() {
  InitPlatformData();
  m_Player->CreateEntity();
}

void World::InitPlatformData() {
  // Initialise the platform data
  m_Renderer2D->CreateQuad(780.0f, 100.0f);
}

void World::OnImGui() {
  ImGui::SliderFloat("Change Camera Rotation", &m_CamRotationDefVal, 0.0f, 360.0f);
  m_Camera->SetRotation(m_CamRotationDefVal);

  float camPosfl[2] = { m_CamDefPos.x, m_CamDefPos.y }; // fl = float
  ImGui::SliderFloat2("Change Camera Position", camPosfl, -500.0f, 500.0f);
  m_Camera->SetPosition({ camPosfl[0], camPosfl[1], 0.0f });

  ImGui::Text("Camera X Coordinate: %f", m_Camera->GetPosition().x);
  ImGui::Text("Camera Y Coordinate: %f", m_Camera->GetPosition().y);
  ImGui::Text("Camera Z Coordinate: %f", m_Camera->GetPosition().z);
}

void World::RenderPlatform() {
  m_Renderer2D->DrawQuad(m_Camera->GetProjectionViewMatrix(), { 0.0f, -100.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }); 
}

void World::Update(GLFWwindow* window) {
  RenderPlatform();

  /* Camera movement testing */

  if(Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_PAGE_DOWN))
  {
    m_Camera->MoveCamera(Freeze::Camera::CameraDIR::CAM_LEFT, 20.0f);
  }
  if(Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_PAGE_UP))
  {
    m_Camera->MoveCamera(Freeze::Camera::CameraDIR::CAM_RIGHT, 20.0f);
  }
  
  m_Player->RenderEntity(m_Camera->GetProjectionViewMatrix());
}

World::~World() {}