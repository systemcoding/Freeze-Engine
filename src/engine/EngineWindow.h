#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "spdlog/spdlog.h"

#include "../engine-testing/RenderTriangle.h"
#include "RenderCommands.h"

#include <iostream>
#include <string>
#include <memory>

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void process_input(GLFWwindow* window);

class EngineWindow {
public:
    EngineWindow(uint32_t width, uint32_t height, const std::string& title);

    GLFWwindow* getWindowInstance() { return m_EngineWindow; }

    ~EngineWindow();
private:
    bool createGLFWWindow(uint32_t width, uint32_t height, const std::string& title);
    void createWindowContext();
    bool initGLEW();
    void setEngineWindowViewport();
    void gameLoop();
private:
    static GLFWwindow* m_EngineWindow;
    std::unique_ptr<RenderTriangle> m_RenderTriangle = std::make_unique<RenderTriangle>();
};