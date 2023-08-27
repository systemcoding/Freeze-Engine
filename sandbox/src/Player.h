#pragma once

#include <GL/glew.h>
#include <memory>

#include "core/Core.h"

#include "renderer/Buffer.h"
#include "renderer/VertexArray.h"
#include "renderer/Shader.h"
#include "renderer/Camera.h"

#include "core/Core.h"

#include "Entity.h"

class Player : public Entity {
public:
    Player();

    void CreateEntity() override;
    void RenderEntity(const glm::mat4& projectionMatrix) override;

    ~Player();
private:
    std::shared_ptr<Freeze::VertexBuffer> m_VertexBuffer = std::make_shared<Freeze::VertexBuffer>();
    std::shared_ptr<Freeze::ElementBuffer> m_ElementBuffer = std::make_shared<Freeze::ElementBuffer>();
    std::shared_ptr<Freeze::VertexArray> m_VertexArray = std::make_shared<Freeze::VertexArray>();
    std::shared_ptr<Freeze::Shader> m_PlayerShader = std::make_shared<Freeze::Shader>();

};