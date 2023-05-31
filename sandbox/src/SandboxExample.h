#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Texture.h"

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
};