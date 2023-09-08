#include "Sandbox.h"

Sandbox::Sandbox() {}

void Sandbox::OnInit()
{
    Freeze::EnableOpenGLDebug();

    // Load World Data First
    m_World->Init();
}

void Sandbox::OnEvent(GLFWwindow *window)
{
    m_Player->MovePlayer(window);    
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
