#include "SandboxExample.h"

SandboxExample::SandboxExample()
    :m_Camera(glm::vec4(-4.0f, 4.0f, -4.0f, 4.0f)) // m_TexturePath("resources/textures/block.png") // default texture path
{
    FZ_INFO("Sandbox Example Calling!");
}

void SandboxExample::OnInit()
{
    Freeze::EnableOpenGLDebug();

    m_Shader->LoadShadersFromFile(rootDir + "shaders/SandboxExample.vert", rootDir + "shaders/SandboxExample.frag");

    m_Texture->GenerateTexture(1, rootDir + "resources/textures/awesomeface.png", GL_RGBA);
    m_Sprite = new Freeze::Sprite(m_Shader);
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
//     float rotation = 0.0f;
//     glm::vec2 cameraPositions(-1.0f, 1.0f);
//     bool my_tool_active = true;

//     float positions[2] = { cameraPositions.x, cameraPositions.y };

//     // ImGui Stuff
//     ImGui::Begin("Settings", &my_tool_active, ImGuiWindowFlags_MenuBar);
//     if (ImGui::SliderFloat("Rotation", &rotation, 0.0f, 360.0f))
//     {
//         m_Camera.SetRotation(rotation);
//     }

//     if (ImGui::SliderFloat2("Camera Positions", positions, -4.0f, 4.0f))
//     {
//         glm::vec3 newPos(positions[0], positions[1], 0.0f);
//         m_Camera.SetPosition(newPos);
//     }

//     // if (ImGui::Button("Choose Texture", ImVec2(110.0f, 20.0f)))
//     // {
//     //     ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Select Texture File", ".png,.jpg,.jpeg", rootDir);
//     // }

//     // if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"))
//     // {
//     //     // action if OK
//     //     if (ImGuiFileDialog::Instance()->IsOk())
//     //     {
//     //         std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
//     //         std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();

//     //         // action
//     //         m_Texture->GenerateTexture(1, filePathName, GL_RGBA);
//     //     }

//     //     // close
//     //     ImGuiFileDialog::Instance()->Close();
//     // }

//     ImGui::End();
}

void SandboxExample::OnUpdate(float dt, GLFWwindow* window)
{
    m_Shader->UseShader();
    m_Shader->SetMatrix4fv(m_Shader->GetUniformLocation("a_ProjectionViewMat"), m_Camera.GetProjectionViewMatrix());

    m_Sprite->DrawSprite(m_Texture, glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, 1.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}

SandboxExample::~SandboxExample()
{
    delete m_Sprite;
}
