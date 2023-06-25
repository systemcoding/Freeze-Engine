#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"

#include <optional>

namespace Freeze
{
    class Renderer2D
    {
    public:
        Renderer2D();

        void DrawQuad(glm::vec3 position, const std::string& vertexShader, const std::string& fragmentShader);
        void RenderQuad();
        void DrawTexturedQuad();

        ~Renderer2D();

    private:
        std::shared_ptr<Freeze::VertexBuffer> m_VertexBuffer = std::make_shared<Freeze::VertexBuffer>();
        std::shared_ptr<Freeze::VertexArray> m_VertexArray = std::make_shared<Freeze::VertexArray>();
        std::shared_ptr<Freeze::ElementBuffer> m_ElementBuffer = std::make_shared<Freeze::ElementBuffer>();
        std::shared_ptr<Freeze::Shader> m_Shader = std::make_shared<Freeze::Shader>();
    };
};