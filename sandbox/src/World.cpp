#include "World.h"

#include "core/Core.h"

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
  float vertices[] = {
      // x          // y        // z
      10.0f,  100.0f, 0.0f,  // top right
      800.0f,  100.0f, 0.0f,  // bottom right
      800.0f, -100.0f, 0.0f,  // bottom left
      10.0f, -100.0f, 0.0f   // top left
  };

  uint32_t indices[] = {
      0, 1, 3,  // first triangle
      1, 2, 3   // second triangle
  };

  m_ElementBuffer->AddElementBuffer(indices, sizeof(indices), GL_STATIC_DRAW);
  m_ElementBuffer->BindElementBuffer();

  m_VertexArray->AddVertexArray(1);
  m_VertexArray->BindVertexArray();

  m_VertexBuffer->AddVertexBuffer(vertices, sizeof(vertices), GL_STATIC_DRAW);
  m_VertexBuffer->BindVertexBuffer();

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, (void *)0);
  glEnableVertexAttribArray(0);

  m_Shader->LoadShadersFromFiles(
      Freeze::Utils::GetFilePath("assets/shaders/Sandbox.vert"),
      Freeze::Utils::GetFilePath("assets/shaders/Sandbox.frag"));
}

void World::RenderPlatform() {
  m_Shader->UseShader();

  m_Shader->SetMatrix4fv(m_Shader->GetUniformLocation("a_ProjectionViewMatrix"),
                         m_Camera->GetProjectionViewMatrix());

  m_VertexArray->BindVertexArray();
  m_ElementBuffer->BindElementBuffer();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void World::Update() {
  RenderPlatform();
  m_Player->RenderEntity(m_Camera->GetProjectionViewMatrix());
}

World::~World() {}