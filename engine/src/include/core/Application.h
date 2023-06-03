#pragma once

#include <GL/glew.h>

#include "../../../sandbox/src/SandboxExample.h"
#include "../renderer/RenderCommands.h"
#include "../imgui/ImGuiContext.h"
#include "OpenGLDebug.h"
#include "Window.h"

#include "../core/Core.h"

#include <memory>

namespace Freeze
{
    // Callback functions
    inline void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    inline void process_input(GLFWwindow *window);

    class Application
    {
    public:
        Application(uint32_t width, uint32_t height, const std::string &title);

        void Init(uint32_t width, uint32_t height, const std::string &title);
        void Run();
        void SetEngineViewport();

        virtual ~Application();

    private:
        bool InitGLEW();

    private:
        std::shared_ptr<SandboxExample> m_Sandbox{new SandboxExample()};
        std::shared_ptr<Freeze::Window> m_Window;
        std::shared_ptr<Freeze::ImGuiContext> m_ImGuiContext;
    };
};