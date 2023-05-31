#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Engine Headers
#include "utils/Shader.h"
#include "utils/Texture.h"
#include "buffer/Buffer.h"

#include <iostream>
#include <memory>

class SandboxExample {
public:
    SandboxExample();
    
    void OnInit();
    void OnUpdate();
    void OnEvent(GLFWwindow* window);

    ~SandboxExample();
private:
    uint32_t m_VertexBufferObject, m_VertexArrayObject, m_ElementBufferObject;
private:
    std::shared_ptr<Freeze::Shader> m_Shader = std::make_shared<Freeze::Shader>();
    std::shared_ptr<Freeze::Texture> m_Texture = std::make_shared<Freeze::Texture>();
    std::shared_ptr<Freeze::VertexBuffer> m_VertexBuffer = std::make_shared<Freeze::VertexBuffer>();
    std::shared_ptr<Freeze::ElementBuffer> m_ElementBuffer = std::make_shared<Freeze::ElementBuffer>();
};