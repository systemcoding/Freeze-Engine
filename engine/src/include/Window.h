#pragma once

// External includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "spdlog/spdlog.h"

// Engine files
#include "RenderCommands.h"

// STD Library Includes
#include <iostream>
#include <string>
#include <memory>

namespace Freeze
{
    class Window
    {
    public:
        Window();

        bool CreateWindow(uint32_t width, uint32_t height, const std::string &title);
        void CreateWindowContext();
        GLFWwindow *getWindowInstance() { return m_Window; }

        ~Window();

    private:
        static GLFWwindow *m_Window;
    };
};