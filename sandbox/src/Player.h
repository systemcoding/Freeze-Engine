#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>


#include <memory>

#include "renderer/Buffer.h"
#include "renderer/VertexArray.h"
#include "renderer/Shader.h"
#include "renderer/Camera.h"

#include "input/KeyboardInput.h"
#include "input/MouseInput.h"

#include "core/Core.h"

#include <iostream>
#include "Entity.h"

class Player : public Entity {
public:
    Player();

    void CreateEntity() override;
    void RenderEntity(const glm::mat4& projectionMatrix) override;

    void MovePlayer(GLFWwindow* window);

    ~Player();
private:
    std::shared_ptr<Freeze::VertexBuffer> m_VertexBuffer = std::make_shared<Freeze::VertexBuffer>();
    std::shared_ptr<Freeze::ElementBuffer> m_ElementBuffer = std::make_shared<Freeze::ElementBuffer>();
    std::shared_ptr<Freeze::VertexArray> m_VertexArray = std::make_shared<Freeze::VertexArray>();
    std::shared_ptr<Freeze::Shader> m_PlayerShader = std::make_shared<Freeze::Shader>();
private:
    glm::mat4 m_PlayerMove = glm::mat4(1.0f); 
    float m_X, m_Y;
};