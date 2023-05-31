#include "spdlog/spdlog.h"

#include "../../engine/src/include/Window.h"
#include "../../engine/src/include/Application.h"

class SandboxApp : public Application 
{
public:
    SandboxApp()
        :Application(800, 600, "Sandbox")
    {
        spdlog::info("Sandbox!");
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