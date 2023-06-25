#include "SandboxExample.h"

SandboxExample::SandboxExample()
{
}

void SandboxExample::OnInit()
{
    // texture attribute
    // glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    // glEnableVertexAttribArray(2);

    // m_Shader->LoadShadersFromFile(rootDir + "shaders/SandboxExample.vert", rootDir + "shaders/SandboxExample.frag");
    // m_Shader->UseShader();

    // m_Texture->GenerateTexture(1, rootDir + "resources/textures/pop_cat.png", GL_RGBA);

    m_Renderer2D->DrawQuad(glm::vec3(0.0f, 0.0f, 0.0f), rootDir + "shaders/SandboxExample.vert", rootDir + "shaders/SandboxExample.frag");
}

void SandboxExample::OnInput(GLFWwindow *window)
{
    if (Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_ESCAPE))
    {
        FZ_INFO("Pressed Escape Key and Window Closed!");
        glfwSetWindowShouldClose(window, true);
    }
    if (Freeze::MouseInput::IsMousePressed(window, GLFW_MOUSE_BUTTON_LEFT))
    {
        FZ_INFO("Pressed Left Mouse Button");
    }
}

void SandboxExample::OnUpdate(float dt, GLFWwindow *window)
{
    FZ_INFO("Mouse Coordinates are: {}, {}", m_MouseInput->GetMouseCoords(window).first, m_MouseInput->GetMouseCoords(window).second);

    m_Renderer2D->RenderQuad();
}

SandboxExample::~SandboxExample()
{
}