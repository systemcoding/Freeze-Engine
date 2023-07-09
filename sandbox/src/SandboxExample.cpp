#include "SandboxExample.h"

SandboxExample::SandboxExample()
    :m_Camera(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f))
{
    FZ_INFO("Sandbox Example Calling!");
}

void SandboxExample::OnInit()
{
    Freeze::EnableOpenGLDebug();

    float vertices[] = {
        // first triangle
        -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f, // right
        -0.45f, 0.5f, 0.0f, // top 

        // second triangle
        0.0f, -0.5f, 0.0f,  // left
        0.9f, -0.5f, 0.0f,  // right
        0.45f, 0.5f, 0.0f   // top 
    };

    // Vertex Array Object
    m_VertexArray->AddVertexArray(1);
    m_VertexArray->BindVertexArray();

    // Vertex Buffer Object
    m_VertexBuffer->AddVertexBuffer(1, vertices, sizeof(vertices), GL_STATIC_DRAW);
    m_VertexBuffer->BindVertexBuffer();

    m_Shader->LoadShadersFromFile(rootDir + "shaders/SandboxExample.vert", rootDir + "shaders/SandboxExample.frag");

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void SandboxExample::OnInput(GLFWwindow* window)
{

    if (Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_ESCAPE))
    {
        FZ_WARN("Pressed Escape Key and Window Closed!");
        glfwSetWindowShouldClose(window, true);
    }
    if (Freeze::MouseInput::IsMousePressed(window, GLFW_MOUSE_BUTTON_LEFT))
    {
        FZ_INFO("Pressed Left Mouse Button");
    }
}

void SandboxExample::OnUpdate(float dt, GLFWwindow* window)
{

    m_Shader->UseShader();

    m_Camera.SetRotation(30.0f);

    m_Shader->SetMatrix4fv(m_Shader->GetUniformLocation("a_ProjectionViewMat"), m_Camera.GetProjectionViewMatrix());

    m_VertexArray->BindVertexArray();
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

SandboxExample::~SandboxExample()
{
}