#include "include/EngineWindow.h"

GLFWwindow* EngineWindow::m_EngineWindow;

EngineWindow::EngineWindow()
{
}

bool EngineWindow::CreateWindow(uint32_t width, uint32_t height, const std::string& title)
{
    glfwInit();

    m_EngineWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if(m_EngineWindow == nullptr)
    {
        spdlog::error("Window failed to initialise");
        exit(0);
        return false;
    }

    return true;
}

void EngineWindow::CreateWindowContext()
{
    glfwMakeContextCurrent(m_EngineWindow);
}

EngineWindow::~EngineWindow()
{
    glfwTerminate();
}