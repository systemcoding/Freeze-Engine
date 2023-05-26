#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../engine/Shader.h"
#include "../engine/Texture.h"

#include <iostream>
#include <memory>

class RenderTriangle {
public:
    RenderTriangle();
    
    void create();
    void render();

    ~RenderTriangle();
private:
    uint32_t m_TextureID;
    unsigned int VBO, VAO, EBO;
    int m_Width, m_Height, m_NChannels;
private:
    std::unique_ptr<Shader> m_Shader{new Shader()};
    std::unique_ptr<Texture> m_Texture{new Texture()};
};