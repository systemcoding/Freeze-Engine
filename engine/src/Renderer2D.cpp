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
  
  // This thing needs to be abstracted away (for more flexiblity)
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  m_RendererData->m_RendererShader->LoadShadersFromFiles(Freeze::Utils::GetFilePath("assets/shaders/Player.vert"), 
                                                          Freeze::Utils::GetFilePath("assets/shaders/Player.frag"));
}

void Renderer2D::DrawQuad(const glm::mat4& projectionMatrix, const glm::vec2& positions, const glm::vec4& color) 
{
  m_RendererData->m_RendererShader->UseShader();

  glm::mat4 newPosMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(positions.x, positions.y, 0.0f));

  m_RendererData->m_RendererShader->SetMatrix4fv(m_RendererData->m_RendererShader->GetUniformLocation("a_ProjectionMatrix"), projectionMatrix);
  m_RendererData->m_RendererShader->SetVector4f(m_RendererData->m_RendererShader->GetUniformLocation("u_Color"), color);
  m_RendererData->m_RendererShader->SetMatrix4fv(m_RendererData->m_RendererShader->GetUniformLocation("a_NewPosMatrix"), newPosMatrix);

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
