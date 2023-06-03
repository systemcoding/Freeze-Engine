#include "SandboxExample.h"

SandboxExample::SandboxExample()
{
    m_UtilityManager->PrintCurrentBuildDirectory();
}

void SandboxExample::OnInit()
{
    float vertices[] = {
        // positions          // colors           // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
    };

    uint32_t indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    // Vertex Array Object
    glGenVertexArrays(1, &m_VertexArrayObject);
    glBindVertexArray(m_VertexArrayObject);

    // Vertex Buffer Object
    m_VertexBuffer->AddVertexBuffer(1, vertices, sizeof(vertices), GL_STATIC_DRAW);
    m_VertexBuffer->BindVertexBuffer();

    // Element buffer object
    m_ElementBuffer->AddElementBuffer(1, indices, sizeof(indices), GL_STATIC_DRAW);
    m_ElementBuffer->BindElementBuffer();

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    m_Shader->LoadShadersFromFile(rootDir + "shaders/SandboxExample.vert", rootDir + "shaders/SandboxExample.frag");
    m_Shader->UseShader();

    m_Texture->GenerateTexture(1, "../../resources/textures/pop_cat.png", GL_RGBA);
}

void SandboxExample::OnEvent(GLFWwindow *window)
{
    if (m_KeyboardInput->IsKeyPressed(window, GLFW_KEY_ESCAPE))
    {
        FZ_INFO("Pressed Escape Key and Window Closed!");
        glfwSetWindowShouldClose(window, true);
    }
}

void SandboxExample::OnUpdate()
{
    m_Texture->BindTexture();

    glm::vec3 pos(0.0f, 0.0f, 0.0f);

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, pos);
    trans = glm::rotate(trans, (float)glfwGetTime() * glm::radians(360.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    // Use the shader program
    m_Shader->UseShader();

    // Then set the uniform and stuff
    uint32_t transformLoc = m_Shader->GetUniformLocation("transMatrix");
    m_Shader->SetMatrix4fv(transformLoc, 1, GL_FALSE, trans);

    glBindVertexArray(m_VertexArrayObject);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    bool my_tool_active = true;

    ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open Texture", "Ctrl+O"))
            {
                m_UtilityManager->OpenDirectory(".");
            }
            if (ImGui::MenuItem("Close", "Ctrl+W"))
            {
                my_tool_active = false;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    ImGui::End();
}

SandboxExample::~SandboxExample()
{
}