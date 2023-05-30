#pragma once

#include <GL/glew.h>

#include "../../../sandbox/src/SandboxExample.h"

#include "EngineWindow.h"
#include <memory>

class SandboxApp;

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void process_input(GLFWwindow* window);

class Application {
public:
    Application(uint32_t width, uint32_t height, const std::string& title);

    void Init(uint32_t width, uint32_t height, const std::string& title);
    void Run();
    void SetEngineViewport();

    virtual ~Application();
private:
    bool InitGLEW();
private:
    std::unique_ptr<RenderTriangle> m_RenderTriangle{new RenderTriangle()};
    std::unique_ptr<EngineWindow> m_EngineWindow{new EngineWindow()};
};