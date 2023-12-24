#pragma once

#include <glm/glm.hpp>

#include <memory>

#include "renderer/Buffer.h"
#include "renderer/VertexArray.h"
#include "renderer/Shader.h"
#include "renderer/Camera.h"
#include "renderer/Renderer2D.h"

#include "Player.h"


class World {
public:
    World();

    void Init();
    void InitPlatformData();
    void RenderPlatform();

    glm::mat4 GetCurrentProjectionMatrix() { return m_Camera->GetProjectionViewMatrix(); }
    std::shared_ptr<Player> GetPlayerInstance() { return m_Player; }

    void Update(GLFWwindow* window);

    ~World();
private:
    std::shared_ptr<Freeze::Camera> m_Camera;

    std::shared_ptr<Freeze::VertexBuffer> m_VertexBuffer = std::make_shared<Freeze::VertexBuffer>();
    std::shared_ptr<Freeze::ElementBuffer> m_ElementBuffer = std::make_shared<Freeze::ElementBuffer>();
    std::shared_ptr<Freeze::VertexArray> m_VertexArray = std::make_shared<Freeze::VertexArray>();
    std::shared_ptr<Freeze::Shader> m_Shader = std::make_shared<Freeze::Shader>();
    std::shared_ptr<Freeze::Renderer2D> m_Renderer2D = std::make_shared<Freeze::Renderer2D>();

    std::shared_ptr<Player> m_Player = std::make_shared<Player>();
};