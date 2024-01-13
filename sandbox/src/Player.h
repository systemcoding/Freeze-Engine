#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <imgui.h>

#include <memory>

#include "input/KeyboardInput.h"
#include "input/MouseInput.h"

#include "core/Core.h"

#include "Entity.h"
#include "renderer/Renderer2D.h"
#include "physics/PhysicsBody.h"

class Player : public Entity {
public:
    Player();

    void CreateEntity() override;
    void RenderEntity(const glm::mat4& projectionMatrix) override;

    void OnImGui();

    void MovePlayer(GLFWwindow* window, float dt);

    ~Player();
private:
    std::shared_ptr<Freeze::FreezeQuad> m_FreezeQuad = std::make_shared<Freeze::FreezeQuad>();
    std::shared_ptr<Freeze::FreezeTriangle> m_FreezeTriangle = std::make_shared<Freeze::FreezeTriangle>();

    std::shared_ptr<Freeze::Physics::PhysicsBody> m_PhysicsEntity = std::make_shared<Freeze::Physics::PhysicsBody>();
    std::shared_ptr<Freeze::Physics::PhysicsBody> m_PhysicsEntity1 = std::make_shared<Freeze::Physics::PhysicsBody>();

    glm::mat4 m_PlayerMove = glm::mat4(1.0f); 
    glm::vec4 m_ColorChoose = { 0.3f, 0.6f, 0.4f, 0.2f };
    float m_X, m_Y;
    float playerColors[4] = { m_ColorChoose.r, m_ColorChoose.g, m_ColorChoose.b, m_ColorChoose.a };
};