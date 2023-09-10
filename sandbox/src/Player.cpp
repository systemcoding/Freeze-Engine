#include "Player.h"

Player::Player()
    : Entity("Player"), m_X(0.0f), m_Y(0.0f)
{
    FZ_INFO("Entity: {}", PrintEntityName());
}

void Player::CreateEntity()
{
    FZ_INFO("Hello world");
    float playerCoords[] = {
        100.0f, 100.0f, 0.0f,   // top right
        100.0f, -100.0f, 0.0f,  // bottom right
        -100.0f, -100.0f, 0.0f, // bottom left
        -100.0f, 100.0f, 0.0f   // top left
    };

    uint32_t indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    m_ElementBuffer->AddElementBuffer(indices, sizeof(indices), GL_STATIC_DRAW);
    m_ElementBuffer->BindElementBuffer();

    m_VertexArray->AddVertexArray(1);
    m_VertexArray->BindVertexArray();

    m_VertexBuffer->AddVertexBuffer(playerCoords, sizeof(playerCoords), GL_STATIC_DRAW);
    m_VertexBuffer->BindVertexBuffer();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, (void *)0);
    glEnableVertexAttribArray(0);

    m_PlayerShader->LoadShadersFromFiles(Freeze::Utils::GetFilePath("sandbox/shaders/Player.vert"),
                                         Freeze::Utils::GetFilePath("sandbox/shaders/Player.frag"));
}

void Player::MovePlayer(GLFWwindow* window)
{
    if(Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_D)) // Move Right
    {
        m_X += 20.0f;
    }
    if(Freeze::KeyboardInput::IsKeyPressed(window, GLFW_KEY_A)) // Move Left
    {
        m_X += -20.0f;
    }
}

void Player::RenderEntity(const glm::mat4& projectionMatrix)
{
    m_PlayerShader->UseShader();

    m_PlayerMove = glm::translate(glm::mat4(1.0f), glm::vec3(m_X, 0.0f, 0.0f));

    m_PlayerShader->SetMatrix4fv(m_PlayerShader->GetUniformLocation("a_ProjectionMatrix"), projectionMatrix);
    std::string matrix = glm::to_string(m_PlayerMove);
    m_PlayerShader->SetMatrix4fv(m_PlayerShader->GetUniformLocation("a_InputMatrix"), m_PlayerMove);

    m_VertexArray->BindVertexArray();
    m_ElementBuffer->BindElementBuffer();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Player::~Player()
{
}
