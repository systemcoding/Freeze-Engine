#include "include/Shader.h"

namespace Freeze
{
    Shader::Shader()
    {
    }

    void Shader::LoadShaders(const std::string &vertexShader, const std::string &fragmentShader)
    {
        const GLchar *vertexSource = vertexShader.c_str();
        m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(m_VertexShader, 1, &vertexSource, nullptr);
        glCompileShader(m_VertexShader);

        int resultVertex;
        char infoVertex[1024];
        glGetShaderiv(m_VertexShader, GL_COMPILE_STATUS, &resultVertex);

        if (!resultVertex)
        {
            glGetShaderInfoLog(m_VertexShader, 1024, nullptr, infoVertex);
            spdlog::error("Failed to compile vertex shader {}", infoVertex);
        }

        const GLchar *fragmentSource = fragmentShader.c_str();
        m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(m_FragmentShader, 1, &fragmentSource, nullptr);
        glCompileShader(m_FragmentShader);

        int resultFragment;
        char infoFragment[1024];
        glGetShaderiv(m_FragmentShader, GL_COMPILE_STATUS, &resultFragment);

        if (!resultFragment)
        {
            glGetShaderInfoLog(m_FragmentShader, 1024, nullptr, infoFragment);
            spdlog::error("Failed to compile fragment shader {} ", infoFragment);
        }

        m_ShaderProgramID = glCreateProgram();
        glAttachShader(m_ShaderProgramID, m_VertexShader);
        glAttachShader(m_ShaderProgramID, m_FragmentShader);
        glLinkProgram(m_ShaderProgramID);
    }

    void Shader::UseShader()
    {
        glUseProgram(m_ShaderProgramID);
    }

    void Shader::UnbindShader()
    {
        glUseProgram(0);
    }

    uint32_t Shader::GetUniformLocation(const std::string &uniformName) const
    {
        m_GetUniformLocation = glGetUniformLocation(m_ShaderProgramID, uniformName.c_str());
        return m_GetUniformLocation;
    }

    void Shader::SetMatrix4fv(uint32_t loc, int matrixCount, GLboolean transpose, const glm::mat4 &matrix)
    {
        glUniformMatrix4fv(m_GetUniformLocation, matrixCount, transpose, glm::value_ptr(matrix));
    }

    Shader::~Shader()
    {
        glDeleteShader(m_VertexShader);
        glDeleteShader(m_FragmentShader);
    }
};