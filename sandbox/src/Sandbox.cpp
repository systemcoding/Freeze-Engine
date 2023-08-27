#include "Sandbox.h"

Sandbox::Sandbox() {}

void Sandbox::OnInit()
{
    Freeze::EnableOpenGLDebug();

    // Load World Data First
    m_World->Init();
}

void Sandbox::OnInput(GLFWwindow *window)
{
   
}

void Sandbox::OnImGui()
{
}

void Sandbox::OnUpdate(float dt)
{
    m_World->Update();
}

Sandbox::~Sandbox()
{
}
