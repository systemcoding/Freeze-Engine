#include "include/Application.h"

namespace Freeze
{
    Application::Application(uint32_t width, uint32_t height, const std::string &title)
    {
        Init(width, height, title);
        InitGLEW();
        SetEngineViewport();
    }

    void Application::Init(uint32_t width, uint32_t height, const std::string &title)
    {
        spdlog::info("Engine Running!");
        m_Window = std::make_unique<Freeze::Window>();
        m_Window->CreateWindow(width, height, title);
        m_Window->CreateWindowContext();
    }

    void Application::Run()
    {
        m_Sandbox->OnInit();
        while (!glfwWindowShouldClose(m_Window->getWindowInstance()))
        {
            m_Sandbox->OnEvent(m_Window->getWindowInstance());

            // clear the screen with some color at every start of the frame
            RenderCommands::SetRenderColor(glm::vec4(0.2f, 0.3f, 0.5f, 1.0f));
            RenderCommands::RenderClear();

            // Rendering commands here like (RenderDraw, RenderClear and stuff)
            m_Sandbox->OnUpdate();

            // Then swap the buffers and check for events
            glfwSwapBuffers(m_Window->getWindowInstance());
            glfwPollEvents();
        }
    }

    void Application::SetEngineViewport()
    {
        glViewport(0, 0, 800, 600);
        glfwSetFramebufferSizeCallback(m_Window->getWindowInstance(), framebuffer_size_callback);
    }

    bool Application::InitGLEW()
    {
        if (glewInit() != GLEW_OK)
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

    Application::~Application()
    {
    }
};