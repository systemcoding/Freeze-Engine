#include "SandboxExample.h"

SandboxExample::SandboxExample()
    :m_Camera(glm::vec4(-4.0f, 4.0f, -4.0f, 4.0f)), m_TexturePath("resources/textures/block.png")
{
    FZ_INFO("Sandbox Example Calling!");
}

void SandboxExample::OnInit()
{
    Freeze::EnableOpenGLDebug();

    float vertices[] = {
        // positions          // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
    };

    uint32_t indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    m_ElementBuffer->AddElementBuffer(1, indices, sizeof(indices), GL_STATIC_DRAW);
    m_ElementBuffer->BindElementBuffer();

    // Vertex Array Object
    m_VertexArray->AddVertexArray(1);
    m_VertexArray->BindVertexArray();

    // Vertex Buffer Object
    m_VertexBuffer->AddVertexBuffer(1, vertices, sizeof(vertices), GL_STATIC_DRAW);
    m_VertexBuffer->BindVertexBuffer();

    m_Shader->LoadShadersFromFile(rootDir + "shaders/SandboxExample.vert", rootDir + "shaders/SandboxExample.frag");

    m_Texture->GenerateTexture(1, rootDir + m_TexturePath, GL_RGB);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
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

    if (ImGui::Button("Choose Texture", ImVec2(110.0f, 20.0f)))
    {
        ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Select Texture File", ".png,.jpg", rootDir);
    }

    if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"))
    {
        // action if OK
        if (ImGuiFileDialog::Instance()->IsOk())
        {
            std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
            std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();

            // action
            m_Texture->GenerateTexture(1, filePathName, GL_RGBA);
        }

        // close
        ImGuiFileDialog::Instance()->Close();
    }

    ImGui::End();
}

void SandboxExample::OnUpdate(float dt, GLFWwindow* window)
{

    m_Texture->BindTexture();
    m_Shader->UseShader();

    m_Shader->SetMatrix4fv(m_Shader->GetUniformLocation("a_ProjectionViewMat"), m_Camera.GetProjectionViewMatrix());

    m_VertexArray->BindVertexArray();
    m_ElementBuffer->BindElementBuffer(); // Bind the element buffer object

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

SandboxExample::~SandboxExample()
{
}
