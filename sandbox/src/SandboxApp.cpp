#include "spdlog/spdlog.h"

#include "core/Window.h"
#include "core/Application.h"

class SandboxApp : public Freeze::Application 
{
public:
    SandboxApp()
        :Application(800, 600, "Sandbox")
    {
        spdlog::info("Sandbox App!");
    }

    ~SandboxApp()
    {

    }
};

int main()
{
    SandboxApp* sandboxApp = new SandboxApp();
    sandboxApp->Run();

    delete sandboxApp;

    return 0;
}