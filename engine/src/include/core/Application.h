#pragma once

#include <GL/glew.h>

#include "Core.h"
#include "Window.h"
#include "../../../sandbox/src/Sandbox.h"
#include "../renderer/RenderCommands.h"
#include "../renderer/Renderer2D.h"
#include "../imgui/ImGuiContext.h"

#include <memory>

namespace Freeze
{
    // Callback functions
    inline void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    inline void process_input(GLFWwindow* window);

    class Application
    {
    public:
        void OnInit(uint32_t width, uint32_t height, const std::string& title);
        void OnEvent();
        void Run();

        void SetEngineViewport();

        virtual ~Application();

    private:
        bool InitGLEW();

    private:
        std::shared_ptr<Sandbox> m_Sandbox;
        std::shared_ptr<Freeze::Window> m_Window;
        std::shared_ptr<Freeze::ImGuiContext> m_ImGuiContext;
        std::shared_ptr<Freeze::Renderer2D> m_Renderer2D = std::make_shared<Freeze::Renderer2D>();
    };
};