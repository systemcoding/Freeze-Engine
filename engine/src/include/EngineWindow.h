#pragma once

// External includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "spdlog/spdlog.h"

// Engine files
#include "RenderCommands.h"

// STD Library Includes
#include <iostream>
#include <string>
#include <memory>

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

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
};