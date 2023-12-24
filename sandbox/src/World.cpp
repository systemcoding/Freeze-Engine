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

void World::RenderPlatform() {
  m_Renderer2D->DrawQuad(m_Camera->GetProjectionViewMatrix(), { 0.0f, -100.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }); 
}

void World::Update() {
  RenderPlatform();
  m_Player->RenderEntity(m_Camera->GetProjectionViewMatrix());
}

World::~World() {}