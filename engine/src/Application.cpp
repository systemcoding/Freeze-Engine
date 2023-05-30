#include "include/Application.h"
#include "include/EngineWindow.h"

Application::Application(uint32_t width, uint32_t height, const std::string& title)
{
    Init(width, height, title);
    InitGLEW();
    SetEngineViewport(); 
}

void Application::Init(uint32_t width, uint32_t height, const std::string& title)
{
    spdlog::info("Engine Running!");
    m_EngineWindow = std::make_unique<EngineWindow>();
    m_EngineWindow->CreateWindow(width, height, title);
    m_EngineWindow->CreateWindowContext();
}

void Application::Run()
{
    m_RenderTriangle->create();
    while (!glfwWindowShouldClose(m_EngineWindow->getWindowInstance()))
    {
        process_input(m_EngineWindow->getWindowInstance());

        // clear the screen with some color at every start of the frame
        glm::vec4 color(0.130f, 0.120f, 0.120f, 1.0f);
        RenderCommands::SetRenderColor(color);
        RenderCommands::RenderClear(); 

        // Rendering commands here like (RenderDraw, RenderClear and stuff)
        m_RenderTriangle->render();
        
        // Then swap the buffers and check for events
        glfwSwapBuffers(m_EngineWindow->getWindowInstance());
        glfwPollEvents();
    }
}

void Application::SetEngineViewport()
{
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(m_EngineWindow->getWindowInstance(), framebuffer_size_callback);
}

bool Application::InitGLEW()
{
    if(glewInit() != GLEW_OK)
    {
        spdlog::error("GLEW failed to initialise");
        exit(0);
        return false;
    }

    return true;
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

Application::~Application()
{
}