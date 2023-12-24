#pragma once

#include <GL/glew.h>

#include "Buffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include <core/Core.h>

#include <memory>

namespace Freeze {

class RenderCommands
{
public:
  static void SetRenderColor(const glm::vec4& color);
  static void RenderClear();
};

struct RendererData
{
  std::shared_ptr<Freeze::VertexBuffer> m_VertexBuffer = std::make_shared<Freeze::VertexBuffer>();
  std::shared_ptr<Freeze::ElementBuffer> m_ElementBuffer = std::make_shared<Freeze::ElementBuffer>();
  std::shared_ptr<Freeze::VertexArray> m_VertexArray = std::make_shared<Freeze::VertexArray>();
  std::shared_ptr<Freeze::Shader> m_RendererShader = std::make_shared<Freeze::Shader>();

  float* m_QuadCoords;
  uint32_t* m_QuadIndices;

  float* m_TriangleCoords;
  uint32_t* m_TriangleIndices;
};

class Renderer2D {
public:
  Renderer2D();

  void InitRenderer();
  // Draw primitive shapes (only triangle and quads for now)
  void DrawTriangle();

  void CreateQuad(float width, float height);
  void DrawQuad(const glm::mat4& projectionMatrix, const glm::vec2& positions, const glm::vec4& color);

  void DestoryRenderer();

private:
  RendererData* m_RendererData;
};

}; // namespace Freeze
