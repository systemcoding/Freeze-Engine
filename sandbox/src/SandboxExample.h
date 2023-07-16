#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

// ImGui
#include <imgui.h>
#include <ImGuiFileDialog.h>
#include <imgui_internal.h>

// Engine Headers
#include "core/Core.h"
#include "core/root_dir.h"
#include "renderer/Shader.h"
#include "renderer/VertexArray.h"
#include "renderer/Camera.h"
#include "renderer/Texture.h"
#include "renderer/Buffer.h"
#include "input/KeyboardInput.h"
#include "input/MouseInput.h"
#include "core/OpenGLDebug.h"

#include <iostream>
#include <memory>

class SandboxExample
{
public:
    SandboxExample();

    void OnInit();
    void OnUpdate(float dt, GLFWwindow* window);
    void OnImGui();
    void OnInput(GLFWwindow* window);

    ~SandboxExample();

private:
    std::shared_ptr<Freeze::Shader> m_Shader = std::make_shared<Freeze::Shader>();
    std::shared_ptr<Freeze::Texture> m_Texture = std::make_shared<Freeze::Texture>();
    std::shared_ptr<Freeze::VertexBuffer> m_VertexBuffer = std::make_shared<Freeze::VertexBuffer>();
    std::shared_ptr<Freeze::VertexArray> m_VertexArray = std::make_shared<Freeze::VertexArray>();
    std::shared_ptr<Freeze::ElementBuffer> m_ElementBuffer = std::make_shared<Freeze::ElementBuffer>();
    std::shared_ptr<Freeze::KeyboardInput> m_KeyboardInput = std::make_shared<Freeze::KeyboardInput>();
    std::shared_ptr<Freeze::MouseInput> m_MouseInput = std::make_shared<Freeze::MouseInput>();

    Freeze::Camera m_Camera;
private:
    std::string m_TexturePath;
};