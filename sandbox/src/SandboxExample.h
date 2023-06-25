#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ImGui
#include <imgui.h>
#include <imgui_internal.h>

// Engine Headers
#include "core/Core.h"
#include "core/root_dir.h"

#include "renderer/Renderer2D.h"
#include "renderer/Shader.h"
#include "renderer/Texture.h"
#include "renderer/Buffer.h"
#include "renderer/VertexArray.h"
#include "input/KeyboardInput.h"
#include "input/MouseInput.h"

#include <iostream>
#include <memory>

class SandboxExample
{
public:
    SandboxExample();

    void OnInit();
    void OnUpdate(float dt, GLFWwindow *window);
    void OnInput(GLFWwindow *window);

    ~SandboxExample();

private:
    std::shared_ptr<Freeze::KeyboardInput> m_KeyboardInput = std::make_shared<Freeze::KeyboardInput>();
    std::shared_ptr<Freeze::MouseInput> m_MouseInput = std::make_shared<Freeze::MouseInput>();
    std::shared_ptr<Freeze::Renderer2D> m_Renderer2D = std::make_shared<Freeze::Renderer2D>();
};