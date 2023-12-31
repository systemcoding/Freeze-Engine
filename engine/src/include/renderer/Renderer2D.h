#pragma once

#include <GL/glew.h>

#include "Buffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include <core/Core.h>

#include <memory>

/* TODO: Fix multiple calls from 2D Renderer. 
         Seperate classes for shapes.
*/

namespace Freeze {

class RenderCommands
{
public:
  static void SetRenderColor(const glm::vec4& color);
  static void RenderClear();
};

struct QuadRendererData
{
  std::shared_ptr<Freeze::VertexBuffer> m_VertexBuffer = std::make_shared<Freeze::VertexBuffer>();
  std::shared_ptr<Freeze::ElementBuffer> m_ElementBuffer = std::make_shared<Freeze::ElementBuffer>();
  std::shared_ptr<Freeze::VertexArray> m_VertexArray = std::make_shared<Freeze::VertexArray>();
  std::shared_ptr<Freeze::Shader> m_RendererShader = std::make_shared<Freeze::Shader>();

  float* m_QuadCoords;
  uint32_t* m_QuadIndices;
};

struct TriangleRendererData
{
  std::shared_ptr<Freeze::VertexBuffer> m_VertexBuffer = std::make_shared<Freeze::VertexBuffer>();
  std::shared_ptr<Freeze::ElementBuffer> m_ElementBuffer = std::make_shared<Freeze::ElementBuffer>();
  std::shared_ptr<Freeze::VertexArray> m_VertexArray = std::make_shared<Freeze::VertexArray>();
  std::shared_ptr<Freeze::Shader> m_RendererShader = std::make_shared<Freeze::Shader>();

  float* m_TriangleCoords;
};

class Renderer2D {
public:
  Renderer2D();

  void InitRenderer();
  // Draw primitive shapes (only triangle and quads for now)
  void CreateTriangle(float width, float height, const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
  void DrawTriangle(const glm::mat4& projectionMatrix, const glm::vec2& positions, const glm::vec4& color);

  void CreateQuad(float width, float height, const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
  void DrawQuad(const glm::mat4& projectionMatrix, const glm::vec2& positions, const glm::vec4& color);

  void DestoryRenderer();

private:
  QuadRendererData* m_QuadRendererData;
  TriangleRendererData* m_TriangleRendererData;
};

}; // namespace Freeze
