#pragma once

#include <GL/glew.h>
#include <stb/stb_image.h>
#include <spdlog/spdlog.h>

#include "../engine/Shader.h"

#include <iostream>
#include <memory>

class RenderTriangle {
public:
    RenderTriangle();
    
    void create();
    void render();

    ~RenderTriangle();
private:
    uint32_t m_ShaderProgram, textureID;
    std::unique_ptr<Shader> m_Shader{new Shader()};
    unsigned int VBO, VAO, EBO;
    int m_Width, m_Height, m_NChannels;
};