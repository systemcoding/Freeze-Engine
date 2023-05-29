#include "include/EngineWindow.h"

GLFWwindow* EngineWindow::m_EngineWindow;

EngineWindow::EngineWindow(uint32_t width, uint32_t height, const std::string& title)
{
    createGLFWWindow(width, height, title);
    createWindowContext();
    initGLEW();
    setEngineWindowViewport();
    gameLoop();
}

bool EngineWindow::createGLFWWindow(uint32_t width, uint32_t height, const std::string& title)
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

void EngineWindow::createWindowContext()
{
    glfwMakeContextCurrent(m_EngineWindow);
}

bool EngineWindow::initGLEW()
{
    if(glewInit() != GLEW_OK)
    {
        spdlog::error("GLEW failed to initialise");
        exit(0);
        return false;
    }

    return true;
}

void EngineWindow::setEngineWindowViewport()
{
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(m_EngineWindow, framebuffer_size_callback);
}

void EngineWindow::gameLoop()
{
    while (!glfwWindowShouldClose(m_EngineWindow))
    {
        // clear the screen with some color at every start of the frame
        glm::vec4 color(0.130f, 0.120f, 0.120f, 1.0f);
        RenderCommands::SetRenderColor(color);
        RenderCommands::RenderClear(); 

        // Rendering commands here like (RenderDraw, RenderClear and stuff)

        // Then swap the buffers and check for events
        glfwSwapBuffers(m_EngineWindow);
        glfwPollEvents();
    }
}

// Callback functions
static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

static void process_input(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        spdlog::info("Pressed Escape and Engine Closed");
        glfwSetWindowShouldClose(window, true);
    }
}

EngineWindow::~EngineWindow()
{
    glfwTerminate();
}