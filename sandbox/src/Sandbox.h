#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <memory>

#include "renderer/Camera.h"
#include "core/OpenGLDebug.h"

#include "World.h"

class Sandbox
{
public:
    Sandbox();

    void OnInit();
    void OnImGui();
    void OnInput(GLFWwindow* window);
    void OnUpdate(float dt);

    ~Sandbox();

private:
    std::shared_ptr<World> m_World = std::make_shared<World>();
};
