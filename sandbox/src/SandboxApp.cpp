#include "spdlog/spdlog.h"

#include "../../engine/src/include/EngineWindow.h"
#include "../../engine/src/include/Application.h"

class SandboxApp : public Application 
{
public:
    SandboxApp()
        :Application(800, 600, "OpenGL")
    {
        spdlog::info("Sandbox!");
    }

    void Example()
    {
        spdlog::info("Test Call from sandbox");
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