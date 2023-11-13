#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <memory>

#include "input/KeyboardInput.h"
#include "input/MouseInput.h"

#include "core/Core.h"

#include "Entity.h"
#include "renderer/Renderer2D.h"

class Player : public Entity {
public:
    Player();

    void CreateEntity() override;
    void RenderEntity(const glm::mat4& projectionMatrix) override;

    void MovePlayer(GLFWwindow* window);

    ~Player();
private:
    std::shared_ptr<Freeze::Renderer2D> m_Renderer2D = std::make_unique<Freeze::Renderer2D>();
private:
    glm::mat4 m_PlayerMove = glm::mat4(1.0f); 
    float m_X, m_Y;
};