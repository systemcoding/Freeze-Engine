#include "Player.h"

Player::Player()
    : Entity("Player")
{
    FZ_INFO("Entity: {}", PrintEntityName());
}

void Player::CreateEntity()
{
    FZ_INFO("CREATING PLAYER");
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

void Player::RenderEntity(const glm::mat4& projectionMatrix)
{
    FZ_INFO("player!");
    m_PlayerShader->UseShader();

    m_PlayerShader->SetMatrix4fv(m_PlayerShader->GetUniformLocation("a_ProjectionMatrix"), projectionMatrix);

    m_VertexArray->BindVertexArray();
    m_ElementBuffer->BindElementBuffer();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Player::~Player()
{
}