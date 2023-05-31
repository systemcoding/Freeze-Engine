#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../engine/src/include/Shader.h"
#include "../../engine/src/include/Texture.h"

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
    unsigned int VBO, VAO, EBO;
private:
    std::unique_ptr<Shader> m_Shader{new Shader()};
    std::unique_ptr<Texture> m_Texture{new Texture()};
};