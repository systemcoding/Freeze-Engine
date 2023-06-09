#include "include/core/Window.h"

namespace Freeze
{
    GLFWwindow *Window::m_Window;

    Window::Window()
    {
    }

    bool Window::CreateWindow(uint32_t width, uint32_t height, const std::string &title)
    {
        glfwInit();

        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
        m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        if (m_Window == nullptr)
        {
            spdlog::error("Window failed to initialise");
            exit(0);
            return false;
        }

        return true;
    }

    void Window::CreateWindowContext()
    {
        glfwMakeContextCurrent(m_Window);
    }

    Window::~Window()
    {
        glfwTerminate();
    }
};