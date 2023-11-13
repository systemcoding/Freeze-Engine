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
    ImGui::Begin("Entity Editor: ", &m_OpenImGuiWindow);
    if(ImGui::Button("Create Entity", ImVec2(100.0f, 30.0f)))
    {
    }
    
    ImGui::End();
}

void Sandbox::OnUpdate(float dt)
{
    m_World->Update();
}

Sandbox::~Sandbox()
{
}
