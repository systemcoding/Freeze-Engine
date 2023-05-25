#pragma once

#include <GL/glew.h>
#include <spdlog/spdlog.h>

#include <cstdint>
#include <iostream>
#include <string>

class Shader
{
public:
    Shader();

    void loadShaders(const std::string& vertexShader, const std::string& fragmentShader);
    void useShaderProgram();
    void unbindShaderProgram();

    ~Shader();
private:
    uint32_t m_ShaderProgramID;
    uint32_t m_VertexShader, m_FragmentShader;
};