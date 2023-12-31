#include "Sandbox.h"

bool Sandbox::m_OpenImGuiWindow = true;

Sandbox::Sandbox() {}

void Sandbox::OnInit()
{
    Freeze::EnableOpenGLDebug();

    // Load World Data First
    m_World->Init();
}

void Sandbox::OnEvent(GLFWwindow *window)
{
    m_World->GetPlayerInstance()->MovePlayer(window);    
}

void Sandbox::OnImGui()
{
    ImGui::Begin("Settings", &m_OpenImGuiWindow);

    m_World->GetPlayerInstance()->OnImGui(); 

    ImGui::Dummy(ImVec2(0.0f, 20.0f));

    m_World->OnImGui();

    ImGui::End();
}

void Sandbox::OnUpdate(GLFWwindow* window, float dt)
{
    m_World->Update(window);
}

Sandbox::~Sandbox()
{
}

