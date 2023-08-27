#include "core/Window.h"
#include "core/Application.h"
#include "core/Core.h"

#include "Sandbox.h"

#include <memory>

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
private:
    std::shared_ptr<Sandbox> m_Sandbox = std::shared_ptr<Sandbox>();
};

int main()
{
    SandboxApp *sandboxApp = new SandboxApp();
    sandboxApp->Run();

    delete sandboxApp;

    return 0;
}