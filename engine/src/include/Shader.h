#pragma once

#include <GL/glew.h>

// GLM Math Libraries
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

    uint32_t getShaderProgramID() { return m_ShaderProgramID; }

    uint32_t getUniformLocation(const std::string& uniformName) const;
    void setMatrix4fv(uint32_t loc, int matrixCount, GLboolean transpose, const glm::mat4& matrix);

    ~Shader();
private:
    uint32_t m_ShaderProgramID;
    uint32_t m_VertexShader, m_FragmentShader;
    mutable uint32_t m_GetUniformLocation;
    std::string m_UniformLocation;
};