#include "include/renderer/Renderer2D.h"

namespace Freeze
{
    Renderer2D::Renderer2D()
    {
    }

    void Renderer2D::DrawQuad(glm::vec3 position, const std::string& vertexShader, const std::string& fragmentShader)
    {
        float vertices[] = {
            // positions          // colors           // texture coords
            0.5f, 0.5f, 0.0f, 1.0f, 0.0f,   // top right
            0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
            -0.5f, 0.5f, 0.0f, 1.0f, 1.0f,  // top left
        };

        uint32_t indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };

        // Vertex Array Object
        m_VertexArray->AddVertexArray(1);
        m_VertexArray->BindVertexArray();

        // Vertex Buffer Object
        m_VertexBuffer->AddVertexBuffer(1, vertices, sizeof(vertices), GL_STATIC_DRAW);
        m_VertexBuffer->BindVertexBuffer();

        // Element buffer object
        m_ElementBuffer->AddElementBuffer(1, indices, sizeof(indices), GL_STATIC_DRAW);
        m_ElementBuffer->BindElementBuffer();

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        m_Shader->LoadShadersFromFile(vertexShader, fragmentShader);
        m_Shader->UseShader();
    };

    void Renderer2D::RenderQuad()
    {
        // Use the shader program
        m_Shader->UseShader();

        m_VertexArray->BindVertexArray();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    Renderer2D::~Renderer2D()
    {
    }
};