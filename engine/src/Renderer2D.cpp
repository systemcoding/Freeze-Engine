#include "include/renderer/Renderer2D.h"

namespace Freeze {

void Renderer2D::CreateQuad() {
  m_RendererData->m_QuadCoords = new float[12]{
      100.0f, 100.0f, 0.0f,   // top right
      200.0f, 100.0f, 0.0f,   // bottom right
      200.0f, 200.0f, 0.0f,   // bottom left
      100.0f, 200.0f, 0.0f  // top left
  };

  m_RendererData->m_QuadIndices = new uint32_t[6]{
      0,  1,  3,
      1,  2,  3
  };

  // Lol this sucks... i need to manually assign the sizes due to them being dynamically allocated rather stack allocated (but that's fine)
  m_RendererData->m_ElementBuffer->AddElementBuffer(m_RendererData->m_QuadIndices, 6 * sizeof(uint32_t), GL_STATIC_DRAW);
  m_RendererData->m_ElementBuffer->BindElementBuffer();

  m_RendererData->m_VertexArray->AddVertexArray(1);
  m_RendererData->m_VertexArray->BindVertexArray();

  m_RendererData->m_VertexBuffer->AddVertexBuffer(m_RendererData->m_QuadCoords, 12 * sizeof(float), GL_STATIC_DRAW);
  m_RendererData->m_VertexBuffer->BindVertexBuffer();
  
  // Ahh, this thing needs to be abstracted away (for more flexiblity)...
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  m_RendererData->m_RendererShader->LoadShadersFromFiles(Freeze::Utils::GetFilePath("assets/shaders/Player.vert"), 
                                                          Freeze::Utils::GetFilePath("assets/shaders/Player.frag"));
}

void Renderer2D::DrawQuad(const glm::mat4& projectionMatrix) 
{
  m_RendererData->m_RendererShader->UseShader();

  //m_PlayerMove = glm::translate(glm::mat4(1.0f), glm::vec3(m_X, 0.0f, 0.0f));

  m_RendererData->m_RendererShader->SetMatrix4fv(m_RendererData->m_RendererShader->GetUniformLocation("a_ProjectionMatrix"), projectionMatrix);
  // std::string matrix = glm::to_string(m_PlayerMove);
  // m_PlayerShader->SetMatrix4fv(m_PlayerShader->GetUniformLocation("a_InputMatrix"), m_PlayerMove);

  m_RendererData->m_VertexArray->BindVertexArray();
  m_RendererData->m_ElementBuffer->BindElementBuffer();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer2D::DestoryRenderer() {
  delete[] m_RendererData->m_QuadCoords;
  delete[] m_RendererData->m_QuadIndices;
  delete m_RendererData;
}

};  // namespace Freeze
