#include "spdlog/spdlog.h"

#include "core/Window.h"
#include "core/Application.h"
#include "core/Core.h"

class SandboxApp : public Freeze::Application
{
public:
    SandboxApp()
        : Application(800, 600, "Sandbox")
    {
        FZ_INFO("Sandbox App!");
    }

    ~SandboxApp()
    {
    }
};

int main()
{
    SandboxApp *sandboxApp = new SandboxApp();
    sandboxApp->OnUpdate();

    delete sandboxApp;

    return 0;
}