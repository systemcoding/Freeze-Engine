#include "SandboxExample.h"

SandboxExample::SandboxExample()
{
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
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Vertex Buffer Object
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Element buffer object
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    std::string vertexShader = R"(
        #version 420 core

        layout (location = 0) in vec3 a_Position;
        layout (location = 1) in vec3 a_Color;
        layout (location = 2) in vec2 a_TexCoords;

        out vec3 triangleColor;
        out vec2 textureCoords;

        uniform mat4 transMatrix;

        void main()
        {
            gl_Position = transMatrix * vec4(a_Position, 1.0f);
            triangleColor = a_Color;
            textureCoords = a_TexCoords;
        }
    )";

    std::string fragmentShader = R"(
        #version 420 core

        out vec4 f_TColor;

        in vec3 triangleColor;
        in vec2 textureCoords;

        uniform sampler2D tex0;

        void main()
        {
            f_TColor = texture(tex0, textureCoords);
        }
    )";

    m_Shader->LoadShaders(vertexShader, fragmentShader);
    m_Shader->UseShader();

    m_Texture->GenerateTexture(1, "../../resources/textures/pop_cat.png", GL_RGBA);
}

void SandboxExample::OnEvent(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        spdlog::info("Pressed Escape Key and Window Closed!");
        glfwSetWindowShouldClose(window, true);
    }
}

void SandboxExample::OnUpdate()
{
    m_Texture->BindTexture();

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, (float)glfwGetTime() * glm::radians(20.0f), glm::vec3(0.0, 0.0, 1.0));
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

    // Use the shader program
    m_Shader->UseShader();

    // Then set the uniform and stuff
    uint32_t transformLoc = m_Shader->GetUniformLocation("transMatrix");
    m_Shader->SetMatrix4fv(transformLoc, 1, GL_FALSE, trans);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

SandboxExample::~SandboxExample()
{
}