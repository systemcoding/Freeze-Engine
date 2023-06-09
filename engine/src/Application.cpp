#include "include/core/Application.h"

namespace Freeze
{
    Application::Application(uint32_t width, uint32_t height, const std::string& title)
    {
        OnInit(width, height, title);
        InitGLEW();
        SetEngineViewport();
    }

    void Application::OnInit(uint32_t width, uint32_t height, const std::string& title)
    {
        FZ_INFO("Engine Running!");
        m_Window = std::make_unique<Freeze::Window>();
        m_Window->CreateWindow(width, height, title);
        m_Window->CreateWindowContext();
        m_ImGuiContext->CreateImGuiContext(m_Window->getWindowInstance());
    }

    void Application::OnUpdate()
    {
        m_Sandbox->OnInit();
        while (!glfwWindowShouldClose(m_Window->getWindowInstance()))
        {
            m_Sandbox->OnInput(m_Window->getWindowInstance());
            // clear the screen with some color at every start of the frame
            RenderCommands::SetRenderColor(glm::vec4(0.2f, 0.3f, 0.5f, 1.0f));
            RenderCommands::RenderClear();

            m_Sandbox->OnUpdate(0.23423f, m_Window->getWindowInstance());
            // Setup ImGui
            m_ImGuiContext->UpdateImGui();

            // Render ImGui Stuff
            m_ImGuiContext->RenderImGui();

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

    Application::~Application()
    {
    }

    // Callback functions
    inline void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

};