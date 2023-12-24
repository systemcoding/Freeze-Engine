#include "include/core/Application.h"

namespace Freeze {

void Application::OnInit(uint32_t width, uint32_t height,
                         const std::string &title) {
  m_Window = std::make_unique<Freeze::Window>();
  m_Window->CreateWindow(width, height, title);
  m_Window->CreateWindowContext();

  InitGLEW();
  SetEngineViewport();

  m_ImGuiContext->CreateImGuiContext(m_Window->getWindowInstance());

  m_Sandbox = std::make_shared<Sandbox>();
  m_Sandbox->OnInit();
}

void Application::Run() {
  while (!glfwWindowShouldClose(m_Window->getWindowInstance())) {
    m_Sandbox->OnEvent(m_Window->getWindowInstance());

    // clear the screen with some color at every start of the frame
    Freeze::RenderCommands::SetRenderColor(glm::vec4(0.161, 0.161, 0.133, 1.0f));
    Freeze::RenderCommands::RenderClear();

    // ALWAYS UPDATE IMGUI BEFORE DOING SANDBOX STUFF!!!
    m_ImGuiContext->UpdateImGui();
    m_Sandbox->OnImGui();

    m_Sandbox->OnUpdate(0.23423f);

    // Render ImGui Stuff
    m_ImGuiContext->RenderImGui();

    // Then swap the buffers and check for events
    glfwSwapBuffers(m_Window->getWindowInstance());
    glfwPollEvents();
  }
}

void Application::SetEngineViewport() {
  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(m_Window->getWindowInstance(),
                                 framebuffer_size_callback);
}

bool Application::InitGLEW() {
  if (glewInit() != GLEW_OK) {
    FZ_ERROR("GLEW failed to initialise");
    FZ_EXIT();
  }

  return true;
}

Application::~Application() { m_Renderer2D->DestoryRenderer(); }

// Callback functions
inline void framebuffer_size_callback(GLFWwindow *window, int width,
                                      int height) {
  glViewport(0, 0, width, height);
}

}; // namespace Freeze
