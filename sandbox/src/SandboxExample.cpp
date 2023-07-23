#include "SandboxExample.h"

SandboxExample::SandboxExample()
    :m_Camera(glm::vec4(-4.0f, 4.0f, -4.0f, 4.0f)), m_Shader(new Freeze::Shader()) {}

void SandboxExample::OnInit()
{
    Freeze::EnableOpenGLDebug();

    m_Shader->LoadShadersFromFile(Freeze::Utils::GetFilePath("shaders/SandboxExample.vert"), Freeze::Utils::GetFilePath("shaders/SandboxExample.frag"));

    m_Texture->GenerateTexture(1, Freeze::Utils::GetFilePath("resources/sprites/awesomeface.png"), GL_RGBA);
    m_Sprite = std::make_shared<Freeze::Sprite>(m_Shader);
}

void SandboxExample::OnInput(GLFWwindow* window)
{
    if (Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_ESCAPE))
    {
        FZ_WARN("Pressed Escape Key and Window Closed!");
        glfwSetWindowShouldClose(window, true);
    }
}

void SandboxExample::OnImGui()
{
    float rotation = 0.0f;
    glm::vec2 cameraPositions(-1.0f, 1.0f);
    bool my_tool_active = true;

    float positions[2] = { cameraPositions.x, cameraPositions.y };

    // ImGui Stuff
    ImGui::Begin("Settings", &my_tool_active, ImGuiWindowFlags_MenuBar);
    if (ImGui::SliderFloat("Rotation", &rotation, 0.0f, 360.0f))
    {
        m_Camera.SetRotation(rotation);
    }

    if (ImGui::SliderFloat2("Camera Positions", positions, -4.0f, 4.0f))
    {
        glm::vec3 newPos(positions[0], positions[1], 0.0f);
        m_Camera.SetPosition(newPos);
    }

    ImGui::End();
}

void SandboxExample::OnUpdate(float dt, GLFWwindow* window)
{
    m_Shader->UseShader();
    m_Shader->SetMatrix4fv(m_Shader->GetUniformLocation("a_ProjectionViewMat"), m_Camera.GetProjectionViewMatrix());

    m_Sprite->DrawSprite(m_Texture, glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, 1.0f), 45.0f);
}

SandboxExample::~SandboxExample()
{
}
